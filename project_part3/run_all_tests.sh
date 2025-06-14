#!/bin/bash

# Colors for output
GREEN='\033[0;32m'  # Green for success
RED='\033[0;31m'    # Red for failure
YELLOW='\033[1;33m' # Yellow for warnings or error output
NC='\033[0m'        # No Color (reset)

# Compile the lexer and parser
lex part3.l
yacc part3.y
cc -o p3 y.tab.c -ll -Ly

# Directory containing test files
test_dir="test_cases_3"

# Initialize counters for total and successful tests
count_all=0
count_suc=0

# Loop over all .t test files
for test_file in "$test_dir"/*.t; do
    test_name=$(basename "$test_file")  # Get the test filename without the directory path
    count_all=$((count_all + 1))        # Increment the total test count
    
    # Run the parser and capture both output and signal status
    output=$(./p3 < "$test_file" 2>&1)
    exit_status=$?

    # Check if the filename starts with 'i' (expected to fail)
    if [[ $(basename "$test_file") == i* ]]; then
        if [ $exit_status -ne 0 ]; then
            echo -e "${GREEN}$(basename "$test_file") failed as expected ✅ (expected to fail)${NC}"
            count_suc=$((count_suc + 1))
        else
            echo -e "${RED}$(basename "$test_file") succeeded ❌ (but was expected to fail)${NC}"
        fi
    else
        if [ $exit_status -eq 0 ]; then
            echo -e "${GREEN}$(basename "$test_file") succeeded ✅${NC}"
            count_suc=$((count_suc + 1))
        else
            echo -e "${RED}$(basename "$test_file") failed ❌${NC}"
            echo -e "${YELLOW}${output}${NC}"
            if [ $exit_status -gt 128 ]; then
                signal=$((exit_status - 128))
                echo -e "${RED}Terminated by signal: $signal (possible segfault or crash) ❌${NC}"
            fi
        fi
    fi
done

# Final summary
echo -e "${GREEN}Total successful tests: ${count_suc}/${count_all}${NC}"
