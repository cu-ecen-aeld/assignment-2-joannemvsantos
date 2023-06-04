#!/bin/bash
filesdir=$1
searchstr=$2

if [ -z "$1" ]
    then
        exit 1
elif [ -z "$2" ]
    then
        exit 1
fi

if [ ! -d "$1" ]
    then
        exit 1
fi

x=`find $filesdir | wc -l`
x=$((x-1))
y=`grep -lr "$searchstr" $filesdir | wc -l`

echo "The number of files are $x and the number of matching lines are $y"

exit 0