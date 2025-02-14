#!/bin/zsh

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to check if norminette is installed
check_norminette() {
    if ! command -v norminette &> /dev/null; then
        echo "${RED}Error: norminette is not installed${NC}"
        echo "Please install norminette first"
        exit 1
    fi
}

# Function to check files
check_files() {
    local error_count=0
    local files_checked=0

    # Find all .c and .h files in current directory and subdirectories
    for file in **/*.c **/*.h(.N); do
        if [ -f "$file" ]; then
            ((files_checked++))
            result=$(norminette "$file")
            if echo "$result" | grep -q "Error!"; then
                echo "${RED}Norm error in: $file${NC}"
                echo "$result"
                ((error_count++))
            else
                echo "${GREEN}$file: OK${NC}"
            fi
        fi
    done

    echo "\nFiles checked: $files_checked"
    
    if [ $error_count -eq 0 ]; then
        echo "${GREEN}All files respect the norm! ✅${NC}"
        return 0
    else
        echo "${RED}Found $error_count files with norm errors ❌${NC}"
        return 1
    fi
}

# Main execution
echo "Checking norminette..."
check_norminette
echo "Starting norm check for .c and .h files..."
check_files