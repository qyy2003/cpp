g++ -o d d.cpp -lm
g++ -o rand rand.cpp -lm
g++ -o ddd ddd.cpp -lm
i=1;
while true; do
    ./rand>data.in
    ./ddd<data.in>data.out
    ./d<data.in>da.out
    echo test $i
    if diff da.out data.out -b; then
	echo AC
    else
	echo WA
	cat da.out
	echo -----------
	cat data.out
	exit
    fi
    i=$(($i+1))
done
