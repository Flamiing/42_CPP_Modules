#!/bin/bash

cd ../ex02

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

result=$(cat ./tester/my_result.txt | grep "Error" |wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST OVERFLOW PASSED!\033[0m"
else
	echo -e "\033[31mTEST OVERFLOW FAILED!\033[0m"
fi

# RIDICULOUS BIG NUMBER TEST #
unsorted_numbers="3452345234523453253245390458239058902348509234850923845098234509823094583204958023948509238509238450923850923845098230594832095482304852039458230945802348502385402384502348592304582309485023945830492582309582349058234095832904582340958320945832094583420958230945832409583240958324095832094582430958230945823094582340958209345823409584209358320958230958230958423095842309582340958230958324058230458423095823049580295820934850423854093285029438509238454902358234098509234582340958230958423058324058320583429058342058324509328503428528934502345092348502348592453245423532453253245832958239058234095809324850923485092348509823509823450982309582390458092384509328509328509845095823490582390458932458239485923845092385098234905832094582034580932850932452147483647 3 2 1"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | grep "Error" |wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST RIDICULOUS BIG NUMBER PASSED!\033[0m"
else
	echo -e "\033[31mTEST RIDICULOUS BIG NUMBER FAILED!\033[0m"
fi

# NEGATIVE NUMBER TEST #
unsorted_numbers="-123 3 2 1"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | grep "Error"  | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST NEGATIVE NUMBER PASSED!\033[0m"
else
	echo -e "\033[31mTEST NEGATIVE NUMBER FAILED!\033[0m"
fi

# DUPLICATED NUMBER TEST #
unsorted_numbers="3 3 2 1"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | grep "Error"  | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST DUPLICATE NUMBER PASSED!\033[0m"
else
	echo -e "\033[31mTEST DUPLICATE NUMBER FAILED!\033[0m"
fi

# NOT A NUMBER TEST #
unsorted_numbers="33 234 4 54353453 3 a j"

my_result=$(./PmergeMe $unsorted_numbers | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | grep "Error"  | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST CHAR THAT IS NOT NUMBER PASSED!\033[0m"
else
	echo -e "\033[31mTEST CHAR THAT IS NOT NUMBER FAILED!\033[0m"
fi

# NO INPUT TEST #
my_result=$(./PmergeMe | grep "Error")
echo $my_result > ./tester/my_result.txt

result=$(cat ./tester/my_result.txt | grep "Error"  | wc -l)

if [ $result != 0 ]; then
    echo -e "\033[32mTEST NO INPUT PASSED!\033[0m"
else
	echo -e "\033[31mTEST NO INPUT FAILED!\033[0m"
fi

rm -rf tester
