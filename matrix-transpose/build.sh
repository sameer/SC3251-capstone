#!/bin/bash
echo "JNI looping"
g++ -O3 -lc -msse -msse2 -ftree-vectorizer-verbose=2 -fPIC -I"$JAVA_HOME/include/" -I"$JAVA_HOME/include/linux/" nativeloop.c -shared -o libnativeloop.so
javac nativeloop.java
time java -Xms512M -Xmx512M -Djava.library.path=. nativeloop

echo ""

echo "C looping"
gcc -O3 loop.c -o loop
time ./loop

echo ""

echo "Java looping"
time java -Xms512m -Xmx512m loop
