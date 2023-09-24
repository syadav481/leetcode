#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

number="$1"

cpp_filename="${number}.cpp"
py_filename="${number}.py"

touch "$py_filename"
cp template_lc.cpp "$cpp_filename"

echo "Created files: $cpp_filename and $py_filename"

git add . 
git commit -m "Problem: $number"
