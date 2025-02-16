#!/bin/bash

# ANSI color codes
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to generate unique random numbers (including negative)
generate_unique_random_numbers() {
    local count=$1
    local min_number=-2147483648
    local max_number=2147483647
    local unique_numbers=()
    local random_number

    while [ ${#unique_numbers[@]} -lt $count ]; do
        random_number=$(( RANDOM * (RANDOM % 2 ? 1 : -1) ))

        if ! [[ " ${unique_numbers[@]} " =~ " $random_number " ]]; then
            unique_numbers+=("$random_number")
        fi
    done

    echo "${unique_numbers[@]}"
}

# Function to run push_swap and checker
run_test() {
    local count=$1
    local ARG=$(generate_unique_random_numbers $count | tr ' ' ' ')

    # Display generated numbers
    echo -e "${BLUE}Generated numbers: ${NC}$ARG"

    # Store results of push_swap in a variable
    local PUSH_SWAP_OUTPUT=$(./push_swap $ARG)
    local ACTIONS=$(echo "$PUSH_SWAP_OUTPUT" | wc -l)

    # Get checker result using the generated argument and push_swap output
    local RESULT=$(./checker_Mac $ARG <<< "$PUSH_SWAP_OUTPUT")

    if [ "$RESULT" == "OK" ] || [ $ACTIONS -eq 0 ]; then
        if ([ $count -eq 100 ] && [ $ACTIONS -ge 0 ] && [ $ACTIONS -le 700 ]) || 
           ([ $count -eq 500 ] && [ $ACTIONS -ge 0 ] && [ $ACTIONS -le 5500 ]) || 
           ([ $count -eq 5 ] && [ $ACTIONS -ge 0 ] && [ $ACTIONS -le 12 ]) || 
           ([ $count -eq 4 ] && [ $ACTIONS -ge 0 ] && [ $ACTIONS -le 7 ]) || 
           ([ $count -eq 3 ] && [ $ACTIONS -ge 0 ] && [ $ACTIONS -le 3 ]); then
            echo -e "${GREEN}$RESULT ${YELLOW}$ACTIONS${NC}"
        else
            echo -e "${RED}KO ${ACTIONS}${NC}"
            return 1
        fi
    else
        echo -e "${RED}KO${NC}"
        return 1
    fi
    echo -e "${BLUE}------------------------------${NC}"
    return 0
}

# Check for required arguments
if [ $# -ne 2 ]; then
    echo -e "${RED}Usage: $0 <number_of_random_numbers> <number_of_tests>${NC}"
    exit 1
fi

NUMBER_OF_NUMBERS=$1
NUMBER_OF_TESTS=$2
ALL_TESTS_PASS=true

for (( i=1; i<=NUMBER_OF_TESTS; i++ )); do
    echo -e "${BLUE}Test $i for $NUMBER_OF_NUMBERS numbers:${NC}"
    run_test $NUMBER_OF_NUMBERS || ALL_TESTS_PASS=false
done

if [ "$ALL_TESTS_PASS" = true ]; then
    echo -e "${GREEN}All tests are correct!${NC}"
else
    echo -e "${RED}Some tests failed.${NC}"
fi
