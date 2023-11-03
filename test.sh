#!/bin/bash

RED='\033[0;31m'
GRN='\033[0;32m'
NOC='\033[0m'

RESULT=$(./pathfinder 2>&1 >/dev/null)

if [[ $RESULT == 'usage: ./pathfinder [filename]' ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with no arguments\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with no arguments\n"
fi

RESULT=$(./pathfinder file.txt 2>&1 >/dev/null)

if [[ $RESULT == 'error: file file.txt does not exist' ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with non existing file\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with non existing file\n"
fi

RESULT=$(./pathfinder tests/empty 2>&1 >/dev/null)

if [[ $RESULT == 'error: file tests/empty is empty' ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with empty file\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with empty file\n"
fi

RESULT=$(./pathfinder tests/invalid1 2>&1 >/dev/null)

if [[ $RESULT == 'error: line 1 is not valid' ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with invalid first line\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with invalid first line\n"
fi

#invalid num

RESULT=$(./pathfinder tests/duplicate 2>&1 >/dev/null)

if [[ $RESULT == 'error: duplicate bridges' ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with duplicate bridges\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with duplicate bridges\n"
fi

RESULT=$(./pathfinder tests/invalid_sum 2>&1 >/dev/null)

if [[ $RESULT == 'error: sum of bridges lengths is too big' ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with invalid sum of bridges\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with invalid sum of bridges\n"
fi

RESULT=$(./pathfinder tests/example1 >&1)

if [[ $RESULT == $(cat tests/example1_result) ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with one shortest path between islands\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with one shortest path between islands\n"
	printf "\tUSER OUTPUT:\n"
	while IFS= read -r line; do
		printf '\t%s\n' "$line"; 
	done < tests/example1_result

	printf "\tTEST OUTPUT:\n"
	while IFS= read -r line; do
		printf '\t%s\n' "$line"; 
	done < tests/example1_result
fi

RESULT=$(./pathfinder tests/example2 >&1)
TEST=$(cat tests/example2_result)

if [[ $RESULT == $TEST ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}test with several shortest pathes between islands\n"
else
	printf "${RED} ✖ FAILURE ${NOC}test with several shortest pathes between islands\n"
	
	printf "\tUSER OUTPUT:\n"
	while IFS= read -r line; do
		printf '\t%s\n' "$line"; 
	done < "$RESULT"

	printf "\tTEST OUTPUT:\n"
	while IFS= read -r line; do
		printf '\t%s\n' "$line"; 
	done < tests/example1_result
fi

RESULT=$(./pathfinder tests/easy >&1)
TEST=$(cat tests/easy_result)

if [[ $RESULT == $TEST ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}easy\n"
else
	printf "${RED} ✖ FAILURE ${NOC}easy\n"
fi

RESULT=$(./pathfinder tests/medium >&1)
TEST=$(cat tests/medium_result)

if [[ $RESULT == $TEST ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}medium\n"
else
	printf "${RED} ✖ FAILURE ${NOC}medium\n"
fi

RESULT=$(./pathfinder tests/hard >&1)
TEST=$(cat tests/hard_result)

if [[ $RESULT == $TEST ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}hard\n"
else
	printf "${RED} ✖ FAILURE ${NOC}hard\n"
fi

RESULT=$(./pathfinder tests/hardest >&1)
TEST=$(cat tests/hardest_result)

if [[ $RESULT == $TEST ]]
then 
	printf "${GRN} ✔ SUCCESS ${NOC}hardest\n"
else
	printf "${RED} ✖ FAILURE ${NOC}hardest\n"
fi
