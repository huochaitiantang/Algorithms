#/bin/bash

gcc $1 -o test -lm

./test

rm ./test
