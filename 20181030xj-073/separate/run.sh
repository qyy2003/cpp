#!/bin/bash
g++ -o a separate.cpp -lm
time ./a
diff separate.out separate.ans -b
