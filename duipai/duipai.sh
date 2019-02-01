#!/bin/bash
g++ gen.cpp -o gen
g++ std.cpp -o std
g++ brute.cpp -o brute
while true ; do
    echo hello
    ./gen > data.in
    ./std < data.in > std.out
    ./brute <data.in > brute.out
    if diff std.out brute.out -b ; then
        echo AC
    else
        echo WA
        cat std.out 
	echo ------------------------------------
	cat brute.out
        exit 
    fi
done