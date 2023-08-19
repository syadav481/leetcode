#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

number="$1"

cpp_filename="${number}.cpp"
py_filename="${number}.py"

touch "$cpp_filename"
touch "$py_filename"

echo "Created files: $cpp_filename and $py_filename"

git add . 
git commit -m "Problem: $number"
git push 