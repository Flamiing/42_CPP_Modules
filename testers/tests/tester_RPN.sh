#!/bin/bash

cd ../ex01

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" >> my_output
./RPN "7 7 * 7 -" >> my_output
./RPN "1 2 * 2 / 2 * 2 4 - +" >> my_output
./RPN "(1 + 1)" >> my_output
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" >> my_output
./RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" >> my_output
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" >> my_output
./RPN "2 5 * 4 + 3 2 * 1 + /" >> my_output
./RPN "4 4 + 6 2 * + 5 + 5 + 4 * 6 / 2 +" >> my_output
./RPN "7 7 * -7 -" >> my_output
./RPN "7 7 * 7.4 -" >> my_output
./RPN "asdfasf" >> my_output
./RPN "4 4 + 6 2 * + 5 + 5 d 4 * 6 / 2 +" >> my_output
./RPN "9 9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *" >> my_output
./RPN "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" >> my_output
./RPN "" >> my_output
./RPN "2 2" >> my_output
./RPN "2 / / /" >> my_output
./RPN "9 9 * 9 *" >> my_output
./RPN "11 2 +" >> my_output

echo "42
42
0
Error
42
42
15
2
22
Error
Error
Error
Error
Error
3.43368e+30
Error
Error
Error
729
Error" > correct_output

my_output=$(diff my_output correct_output | wc -l)

if [ $my_output -eq 0 ]; then
    echo -e "\033[32mTEST PASSED!\033[0m"
else
	echo -e "\033[31mTEST FAILED!\033[0m"
fi

rm -rf correct_output my_output