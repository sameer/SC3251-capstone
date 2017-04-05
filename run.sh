#!/binbash
name="loop"

echo "JNI Time"
time java -Xms512M -Xmx512M -Djava.library.path=. "native$name"
echo ""

echo "C time"
time bash "$name"
echo ""

echo "Java time"
time java "$name"
echo ""
