#!/bin/bash


echo -e "\033[33mMaking my program...\033[0m"
echo -e "\033[32mmake re\033[0m"
make re
sleep 2
echo -e "\033[33mTesting my program...\033[0m"
sleep 1
echo -e "\033[32m./Harl DEBUG \"DEBUG\" ERROR DEBUG \"WARNING\"\033[0m"
./Harl DEBUG \"DEBUG\" ERROR DEBUG \"WARNING\"
echo -e "\033[32m./Harl ERROR WARNING ERROR DEBUG ERROR INFO\033[0m"
./Harl ERROR WARNING ERROR DEBUG ERROR INFO
echo -e "\033[32m./Harl \"\"\033[0m"
./Harl \"\"
echo -e "\033[32m./Harl NOT A LEVEL\033[0m"
./Harl NOT A LEVEL