#!/bin/bash
g++ -o a separate.cpp -lm
time ./a<separate1.in>separate.out
diff separate.out separate1.ans -b
