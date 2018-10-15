# !/bin/bash
g++ -o AC AC.cpp -lm
i=1;
for item in $file
do
./AC<data$i>my$i.ans
if diff my$i.ans data.in -b ; then
echo "$i AC"
else
echo "$i WA"
	fi
i=$(($i+1))
	done
