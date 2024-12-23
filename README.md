
# Simple Calculator

This project implements a basic calculator capable of evaluating mathematical expressions with support for the following operations:

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)
- Exponentiation (`^`)

The calculator includes validation for input expressions and error handling for invalid inputs or operations (e.g., division by zero).

## Features

1. **Validation of Expressions:** Ensures that the input contains only valid characters and operators.
2. **Evaluation of Expressions:** Parses and calculates results using operator precedence.
3. **Error Handling:** Handles invalid inputs, malformed expressions, and mathematical errors.

## Files

1. **calc.h**
   - Header file declaring the calculator's functions.

2. **main.cpp**
   - Entry point for the program. Reads user input, evaluates expressions, and displays results.

3. **calc.cpp**
   - Implements the core functionality, including expression validation, parsing, and calculation.

4. **tests.cpp**
   - Includes unit tests for validation and calculation functions.

## How to Use

1. Clone the repository:

   ```bash
   git clone https://github.com/username/simple-calculator.git
   cd simple-calculator
   ```

2. Build the project:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the calculator:

   ```bash
   ./calculator
   ```

4. Run the tests:

   ```bash
   ./tests
   ```

## Example

Run the program and input mathematical expressions when prompted. Example session:

```bash
Enter expression: 3 + 2 * 2
Result: 7

Enter expression: 10 / 2 + 5 ^ 2
Result: 27.5

Enter expression: stop
Goodbye!
```

## Unit Tests

The project includes unit tests for validation, operator functions, and calculation:

- Validate correct and incorrect expressions.
- Test edge cases like division by zero and empty inputs.
- Verify correct implementation of operator precedence.

To run the tests, use the command:

```bash
./tests
```
