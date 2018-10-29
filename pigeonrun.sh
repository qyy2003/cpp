#!/bin/bash
g++ -o a zxs.cpp -lm
./a
cat pigeon2.in
echo
echo =========================
cat pigeon.out
echo
echo =========================
cat pigeon2.ans

echo =========================
diff pigeon.out pigeon2.ans
