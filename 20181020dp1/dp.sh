g++ -o my my.cpp -lm
g++ -o spj spj.cpp -lm
g++ -o rand rand.cpp -lm
$i=1
while true; do
./rand>data.in
./my<data.in>my.out
./spj<my.out>spj.out
echo
echo test $i
if diff spj.out data.in -b; then
echo AC
else
    echo WA
    exit
fi
echo
i=$(($i+1))
done
