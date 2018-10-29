#!/bin/bash
g++ -o rand rand.cpp -lm
g++ -o a math.cpp -lm
g++ -o std std.cpp -lm
i=1;
while true; do
./rand
./a
./std<math.in>std.out
echo
echo test $i
i=$(($i+1))
if diff std.out math.out -b; then
    echo AC
else
    echo WA
    echo ======================
    cat math.in
    echo
    echo ----------------------
    echo std
    cat std.out
    echo
    echo =====================
    echo my
    cat math.out
    echo
    exit  
fi
done
