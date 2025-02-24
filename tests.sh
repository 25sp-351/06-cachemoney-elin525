#!/bin/bash

make || { echo "Compilation failed"; exit 1; }

# remove previous cache 
rm -f cache.txt

declare -A test_cases
test_cases=(
    # Valid input cases
    [0]="0 = zero dollars"
    [1]="1 = one cent"
    [10]="10 = ten cents"
    [11]="11 = eleven cents"
    [20]="20 = twenty cents"
    [24]="24 = twenty-four cents"
    [100]="100 = one dollar"
    [165]="165 = one dollar and sixty-five cents"
    [110]="110 = one dollar and ten cents"
    [111]="111 = one dollar and eleven cents"
    [1000]="1000 = ten dollars"
    [1001]="1001 = ten dollars and one cent"
    [1234]="1234 = twelve dollars and thirty-four cents"
    [2000]="2000 = twenty dollars"
    [2011]="2011 = twenty dollars and eleven cents"
    [10100]="10100 = one hundred dollars and ten cents"
    [150000]="150000 = one thousand five hundred dollars"
    [150345]="15345 = one thousand five hundred dollars and thirty-four cents"
    
    # Invalid input cases
    [""]="Usage: ./money_to_text <amount in cents>"
    ["-h"]="Usage: ./money_to_text <amount in cents>"
    ["ab"]="Amount must be a positive integer"
    ["-140"]="Amount must be a positive integer"
    ["100 extra_param"]="Invalid number of arguments"
)

all_passed=true

for input in "${!test_cases[@]}"; do
    expected="${test_cases[$input]}"
    
    # Capture the program output (including stderr)
    output=$(./money_to_text <<< "$input" 2>&1)

    # Compare actual output with expected output
    if [[ "$output" == "$expected" ]]; then
        echo "Test passed: $input"
    else
        echo "Test failed: $input"
        echo "Input: $input"
        echo "Expected: $expected"
        echo "Got:      $output"
        all_passed=false
    fi
done

# Clean up
make clean
