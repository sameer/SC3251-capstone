#!/bin/bash

JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64/

name="matrix_multiply"

echo "Compiling JNI..."
javac "native$name.java"
javah "native$name"
g++ -O3 -fPIC -I"$JAVA_HOME/include/" -I"$JAVA_HOME/include/linux/" "native$name.cpp" -shared -o "lib$name.so"
echo ""


echo "Compiling C++"
g++ -O3 -fPIC "$name.cpp" -o "$name"
echo ""

echo "Compiling Java..."
javac "$name.java"
echo ""

echo "Done!"
