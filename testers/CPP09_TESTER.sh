#!/bin/bash

chmod +x ./tests/tester_btc.sh
chmod +x ./tests/tester_RPN.sh
chmod +x ./tests/tester_PmergeMe.sh

make -C ex00 && make clean -C ex00
make -C ex01 && make clean -C ex01
make -C ex02 && make clean -C ex02
cd ./tests
clear

echo -e "\033[1;36mEXECUTING EX00 TESTER:\033[0m" && sleep 2
./tester_btc.sh && sleep 2
echo -e "\033[1;36mEXECUTING EX01 TESTER:\033[0m" && sleep 2
./tester_RPN.sh && sleep 2
echo -e "\033[1;36mEXECUTING EX02 TESTER:\033[0m" && sleep 2
./tester_PmergeMe.sh
echo -e "\033[1;36mTEST ENDED : )\033[0m"