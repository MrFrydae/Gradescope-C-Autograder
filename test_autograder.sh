#!/bin/bash

(rm -f autograder.zip && cd ./src && zip -FSqr ../autograder.zip . -x '*.o' -x './runner' && cd ../submission && zip -qd ../autograder.zip $(find . -type f))

rm -rf ./autograder

mkdir -p ./autograder/source
mkdir -p ./autograder/results
mkdir -p ./autograder/submission

unzip -q autograder.zip -d ./autograder/source
cp ./autograder/source/run_autograder ./autograder/run_autograder

(cd ./submission && cp -r . ../autograder/submission)

cd ./autograder

./run_autograder | tee ./results/results.json