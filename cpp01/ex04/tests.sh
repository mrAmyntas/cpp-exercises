#!/bin/bash


echo -e "\033[33mMaking my program...\033[0m"
echo -e "\033[32mmake re\033[0m"
make re
sleep 3
echo -e "\033[33mTesting my program...\033[0m"
echo -e "\033[32m./replace Makefile NAME CAKE\033[0m"
./replace Makefile NAME CAKE
sleep 3
echo -e "\033[33mAll 'NAME' occurences should now be 'CAKE'\033[0m"
echo -e "\033[33mchecking...\033[0m"
sleep 2
echo -e "\033[32mdiff Makefile Makefile.replace\033[0m"
diff Makefile Makefile.replace