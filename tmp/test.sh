#!/bin/bash
inn=input
outn=output
myn=my_output
g++ -g  -Wall A.cpp
for test_file in input*
do
	echo
	i=${#inn} 
    tc=${test_file:$i}
	echo test $tc
	echo =======================================
    if ! ./a.out < $inn$tc > $myn$tc; then
        echo RE
        echo ---------------------------------------
        echo in $tc
        cat $inn$tc
    else
        if diff -b $myn$tc $outn$tc; then
            echo AC
        else
            echo WA
            echo ---------------------------------------
            echo in
            cat $inn$tc
            echo ---------------------------------------
        fi
    fi
done
