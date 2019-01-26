g++ -o cmy cmy.cpp -lm
g++ -o std std.cpp -lm
g++ -o rand rand.cpp -lm
i=1
while [ $i -gt 0 ] 
    do
    ./rand>data.in
    ./cmy<data.in>cmy.out
    ./std<data.in>std.out
    echo ------------------
    echo test $i
    if diff cmy.out std.out -b; then
	echo AC
    else
	echo WA
	exit
    fi
    i=$((i+1))
done
     
