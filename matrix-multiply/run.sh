#/bin/bash
name="matrix_multiply"

echo "JNI OpenMP Time"
time java -Xms4G -Xmx4G -Djava.library.path=. "openmpnative$name" $@
echo ""

echo "C++ OpenMP Time"
time "./openmp$name" $@
echo ""

echo "JNI Time"
time java -Xms4G -Xmx4G -Djava.library.path=. "native$name" $@
echo ""

echo "C++ time"
time "./$name" $@
echo ""

echo "Java time"
time java "$name" $@
echo ""

echo "Done!"
