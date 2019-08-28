#!/bin/bash

declare -i num
num=1
cat "file.txt" | while read line
do
    if [ $num == 10 ]; then
       echo $line
       exit 0
    else 
		num=$(($num + 1))
    fi
done

# sed -n 10p file.txt
