# 🧠 Rush 01 – Skyscraper Puzzle Solver🏙️

[![C Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  
[![42 Project](https://img.shields.io/badge/42%20Network-Piscine-blueviolet)](https://42.fr)  
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](./LICENSE)

> A C program that solves a 4x4 Skyscraper puzzle using backtracking, developed as part of the 42 School Piscine curriculum.

---

## 🧩 Overview

**Rush 01** is the second group project I completed during the 42 Piscine. My teammates [Mao](https://github.com/maozeitoun), Alex, and I earned a score of 95, and we're proud of it—this was arguably the most challenging of the three group projects.

> ⏱️ The project had to be completed in just 48 hours, making it feel like a mini-hackathon. Time pressure pushed us to collaborate efficiently, write clean code, and manage version control carefully.

The goal is to implement a C program that solves a **4x4 Skyscraper puzzle** using a recursive backtracking algorithm. The program accepts **16 clues** (representing visible skyscrapers from each side of the grid) and fills in the grid with numbers 1 to 4 so that:

- Each row and column contains each number exactly once.
- All clues are satisfied according to visibility rules.

---

## ⚙️ Implementation Details

### 1. Grid Representation

- The puzzle is stored in a `4x4` integer array: `int grid[4][4]`.
- Each cell holds a number between 1 and 4.
- Rows and columns must contain unique values.
- Clues are stored in an `int clues[16]` array.
- The grid is initially empty and filled using backtracking.

### 2. Input Handling

- The program takes **exactly 16 space-separated numbers** as input.
  
  Example:
  ```bash
  ./rush-01 "1 4 2 2 4 1 2 2 1 2 3 2 3 2 1 2"
  ```

- Parsing and validation are handled in `input.c`:
  - Rejects non-numeric input (e.g., `"4 3 X 1 ..."` results in `"Error"`).
  - Ensures the input contains exactly 16 numbers.
  - Validates that numbers are within the range [1, 4].

### 3. Clue Validation

- Each clue represents the number of visible skyscrapers from a side.
- Taller buildings block the view of shorter ones behind them.
- The `count_visible_xx()` functions count visible buildings.
- The `check_clues()` function verifies the grid against all clues.

### 4. Backtracking Algorithm

- `solve_skyscraper()` is the core solver:
  - Starts at cell (0,0).
  - Tries placing numbers 1 through 4.
  - Uses helper functions like `isSafe()` to check for conflicts.
  - Recursively continues until a valid solution is found or backtracks when stuck.

---

## 🔧 How to Compile

```bash
cc -Wall -Wextra -Werror *.c -o rush-01
```
---

## 💡 Notes

- This project reinforces understanding of recursion, backtracking, and input validation.
- A great way to practice algorithmic thinking in C.
- You can test your own puzzles or play interactively using this external site:
  🌐 [puzzle-skyscrapers.com](https://www.puzzle-skyscrapers.com/)  
  It’s a fun way to experiment with clues and compare them with our solver’s results.

### 🛠️ C Functions & Commands Used

| Function / Command | Location(s) | Description |
|--------------------|----------------|---------|
| `write()` | `utils.c`, `print.c` | Prints characters and numbers to standard output. |
| `ft_putchar()` | `utils.c` | Prints a single character (wrapper for `write()`). |
| `ft_putstr()` | `utils.c` | Prints a string (wrapper for `write()`). |
| `ft_putnbr()` | `utils.c` | Prints an integer recursively using `write()`. |
| `ft_atoi()` | `input.c` | Converts a string to an integer. |
| `norminette` | Terminal | Checks code for compliance with 42 coding style. |
| `return` | Throughout the project | Terminates functions and returns values. |
| `if`, `else` | Throughout the project | Implements conditional logic. |
| `while` | Throughout the project | Implements loops for iteration. |
| `int` | Throughout the project | Declares integer variables and return types. |
| `char` | `input.c`, `utils.c` | Represents characters and strings. |
| `void` | `utils.c`, `print.c` | Specifies functions that do not return a value. |
| `#define` | `rush01.h` | Defines constants like `GRID_SIZE`, `TRUE`, `FALSE`. |
| `#include` | All `.c` files | Includes necessary header files. |
| `Static arrays` | `rush01.c`, `isSafe.c`, `visibility.c`, `input.c` | Used for storing the puzzle grid and clues. |
| `Pointers (*)` | `input.c`, `backtracking.c`, `rush01.h` | Passes arrays and modifies data by reference. |
| `Address-of operator (&)` | `backtracking.c` | Passes variable addresses to functions. |
| `Arithmetic operators (+, -, *, /, %)` | Throughout the project | Performs numeric calculations. |
| `Comparison operators (==, !=, <, >, <=, >=)` | Throughout the project | Used in condition checks. |
| `Logical operators (&&, ||, !)` | Throughout the project | Combines multiple conditions in `if` statements. |

---

## ✉️ License

This project is licensed under the [MIT License](./LICENSE).

---

Happy puzzling! 🚀
