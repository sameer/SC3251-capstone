#!/bin/bash

JAVA_HOME=/usr/lib/jvm/java-openjdk/

name="matrix_multiply"

echo "Compiling JNI..."
javac "native$name.java"
javah "native$name"
icpc++ -vec_report2 -xHost -fPIC -I"$JAVA_HOME/include/" -I"$JAVA_HOME/include/linux/" "native$name.cpp" -shared -o "lib$name.so"
echo ""

echo "Compiling OpenMP JNI..."
javac "openmpnative$name.java"
javah "openmpnative$name"
icpc++ -openmp -vec_report2 -xHost -fPIC -I"$JAVA_HOME/include/" -I"$JAVA_HOME/include/linux/" "openmpnative$name.cpp" -shared -o "libopenmp$name.so"
echo ""

echo "Compiling C++..."
icpc++ -vec_report2 -xHost -fPIC "$name.cpp" -o "$name"
echo ""

echo "Compiling OpenMP C++..."
icpc++ -openmp -vec_report2 -xHost -fPIC "openmp$name.cpp" -o "openmp$name"
echo ""


echo "Compiling Java..."
javac "$name.java"
echo ""

echo "Done!"
