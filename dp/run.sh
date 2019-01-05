g++ -o rand rand.cpp -lm
g++ -o my1 my1.cpp -lm
g++ -o my2 my2.cpp -lm
./rand>a.in
./my1<a.in>a.out
./my2<a.in>b.out
while diff a.out b.out -b; do
    ./rand>a.in
    ./my1<a.in>a.out
    ./my2<a.in>b.out
    echo AC
done
echo WA
