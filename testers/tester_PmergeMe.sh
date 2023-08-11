#!/bin/bash

mkdir -p tester

# SIMPLE TEST #
unsorted_numbers="3 5 9 7 4"

my_result=$(./PmergeMe $unsorted_numbers | grep "After:	" | sed 's/After:	//')
echo $my_result > ./tester/my_result.txt

sort_result=$(echo "$unsorted_numbers" | tr " " "\n" | sort -n)
echo $sort_result > ./tester/sort_result.txt

comparation_result=$(diff ./tester/sort_result.txt ./tester/my_result.txt | wc -l)

if [ $comparation_result -eq 0 ]; then
    echo -e "\033[32mTEST 5 UNSORTED NUMBERS PASSED!\033[0m"
else
	echo -e "\033[31mTEST 5 UNSORTED NUMBERS FAILED!\033[0m"
fi

# NORMAL TEST #
unsorted_numbers=$(shuf -i 1-100000 -n 500 | tr "\n" " ")

my_result=$(./PmergeMe $unsorted_numbers | grep "After:	" | sed 's/After:	//')
echo $my_result > ./tester/my_result.txt

sort_result=$(echo "$unsorted_numbers" | tr " " "\n" | sort -n)
echo $sort_result > ./tester/sort_result.txt

comparation_result=$(diff ./tester/sort_result.txt ./tester/my_result.txt | wc -l)

if [ $comparation_result -eq 0 ]; then
    echo -e "\033[32mTEST 500 UNSORTED NUMBERS PASSED!\033[0m"
else
	echo -e "\033[31mTEST 500 UNSORTED NUMBERS FAILED!\033[0m"
fi

# MEDIUM TEST #
unsorted_numbers=$(shuf -i 1-100000 -n 1000 | tr "\n" " ")

my_result=$(./PmergeMe $unsorted_numbers | grep "After:	" | sed 's/After:	//')
echo $my_result > ./tester/my_result.txt

sort_result=$(echo "$unsorted_numbers" | tr " " "\n" | sort -n)
echo $sort_result > ./tester/sort_result.txt

comparation_result=$(diff ./tester/sort_result.txt ./tester/my_result.txt | wc -l)

if [ $comparation_result -eq 0 ]; then
    echo -e "\033[32mTEST 1000 UNSORTED NUMBERS PASSED!\033[0m"
else
	echo -e "\033[31mTEST 1000 UNSORTED NUMBERS FAILED!\033[0m"
fi

# COMPLEX TEST #
unsorted_numbers=$(shuf -i 1-100000 -n 3000 | tr "\n" " ")

my_result=$(./PmergeMe $unsorted_numbers | grep "After:	" | sed 's/After:	//')
echo $my_result > ./tester/my_result.txt

sort_result=$(echo "$unsorted_numbers" | tr " " "\n" | sort -n)
echo $sort_result > ./tester/sort_result.txt

comparation_result=$(diff ./tester/sort_result.txt ./tester/my_result.txt | wc -l)

if [ $comparation_result -eq 0 ]; then
    echo -e "\033[32mTEST 3000 UNSORTED NUMBERS PASSED!\033[0m"
else
	echo -e "\033[31mTEST 3000 UNSORTED NUMBERS FAILED!\033[0m"
fi

# OVERFLOW TEST #
unsorted_numbers="2147483648 3 2 1"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST OVERFLOW PASSED!\033[0m"
else
	echo -e "\033[31mTEST OVERFLOW FAILED!\033[0m"
fi

# NEGATIVE NUMBER TEST #
unsorted_numbers="-123 3 2 1"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST NEGATIVE NUMBER PASSED!\033[0m"
else
	echo -e "\033[31mTEST NEGATIVE NUMBER FAILED!\033[0m"
fi

# DUPLICATED NUMBER TEST #
unsorted_numbers="3 3 2 1"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST DUPLICATE NUMBER PASSED!\033[0m"
else
	echo -e "\033[31mTEST DUPLICATE NUMBER FAILED!\033[0m"
fi

# NOT A NUMBER TEST #
unsorted_numbers="33 234 4 54353453 3 a j"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST CHAR THAT IS NOT NUMBER PASSED!\033[0m"
else
	echo -e "\033[31mTEST CHAR THAT IS NOT NUMBER FAILED!\033[0m"
fi

# NO INPUT TEST #
my_result=$(./PmergeMe | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST NO INPUT PASSED!\033[0m"
else
	echo -e "\033[31mTEST NO INPUT FAILED!\033[0m"
fi

rm -rf tester
