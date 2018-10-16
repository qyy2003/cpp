#!/bin/bash
g++ -g  -Wall a.cpp
i=1
for (( i=1;i<= 100 ;i= i + 1 )) ;do
echo 
echo test $i
echo =======================================
if ! ./a.out < $i.in > $i.out; then
echo RE
echo ---------------------------------------
echo in $i
cat $i.in
echo	
echo !
echo !
echo !
echo !
echo !
else
if diff -b $i.ans $i.out; then
echo AC
else
echo WA
echo ---------------------------------------
echo in
cat $i.in
echo
echo ---------------------------------------
echo EXout
cat $i.ans
echo
echo ---------------------------------------
echo myout
cat $i.out
echo
echo --------------------------------------
echo !
echo !
echo !
echo !
echo !
fi
fi
done
