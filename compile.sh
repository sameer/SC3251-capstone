#!/bin/bash
name="loop"

g++ -O3 -lc -msse -msse2 -ftree-vectorizer-verbose=2 -fPIC -I"$JAVA_HOME/include/" -I"$JAVA_HOME/include/linux/" "native$name.c" -shared -o "lib$name.so"

g++ -O3 "$name.c" -o "$name"

javac "$name.java"
