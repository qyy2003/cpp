#!/bin/bash
g++ -o a zhanshajihua.cpp -lm
./a
diff zhanshajihua.out zhanshajihua.ans -b
