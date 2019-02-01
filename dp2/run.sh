#!/bin/bash
g++ -o my my.cpp -lm
g++ -o std std.cpp -lm
g++ -o rand rand.cpp -lm
while true ; do
    ./rand>data.in
    time ./std<data.in>std.out
    time ./my<data.in>my.out
    if diff my.out std.out -b; then 
	echo AC
    else
	echo WA
	exit
    fi
done
