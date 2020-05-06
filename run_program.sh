#!/bin/bash
gcc -c $1 $2;
IFS='.c ' read -ra files <<< "$1$2";
gcc -o ${files[0]} "${files[0]}.o" "${files[2]}.o";
./${files[0]};