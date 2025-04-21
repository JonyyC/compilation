# Compilation Project

This project is a basic compiler written using **Lex (Flex)** and **Yacc (Bison)**. It implements the first part of a custom programming language (detailed in the `project-language` file), focusing on the scanner and parser components.

## 🧩 Project Structure

- `part1.l` – Lex file (scanner)
- `part1.y` – Yacc/Bison file (parser)
- `test_cases/` – Directory containing sample test cases
- `run_all_tests.sh` – Bash script to compile the project and run all tests automatically
- `project-language` – Description of the language's grammar and syntax rules


## 🖥️ Development Environment

- **Editor:** Visual Studio Code  
- **OS:** Ubuntu (via Windows Subsystem for Linux - WSL)


## 📦 Dependencies

Install the necessary tools using:

```bash
sudo apt-get install flex bison -y
```


## 🔨 How to Compile and Run (Manualy)
# Step 1: Generate scanner
 - lex part1.l

# Step 2: Generate parser
 - bison part1.y

# Step 3: Compile everything
 - cc -o p1 y.tab.c -ll -ly

# Step 4: Run with input test file
 - ./p1 < test1.t


## 🚀 Compile and Run All Tests Automatically

You can use the included script to compile and run all test cases at once:
- `./run_all_tests.sh` 
This script:
- Compiles the Lex and Yacc files
- Builds the final executable
- Runs it on all test files inside the test_cases/ directory


# 📝 Notes

- The language definition is available in the Language file inside project-langauage directory.
- You can extend the test suite by adding more .t files to the tests/ directory.
- Output is printed directly to the terminal. You can redirect it to files if needed.
