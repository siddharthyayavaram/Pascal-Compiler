# Pascal Compiler Implementation

A complete compiler implementation for Pascal programming language, progressing through all phases of compilation from lexical analysis to program execution.

## Project Structure

The project consists of 5 progressive tasks, each building upon the previous:

1. **Lexical Analyzer** - Token generation using Flex
2. **Syntax Analyzer** - Grammar validation using Yacc/Bison  
3. **Semantic Analyzer** - Type checking and variable validation
4. **Code Generator** - Three-address code generation
5. **Interpreter** - Direct program execution with runtime semantics

## Supported Language Features

### Data Types
- Primitive: `Integer`, `Real`, `Boolean`, `Char`
- Arrays: `array[lower..upper] of type`

### Control Structures
- Conditional: `if-then-else`
- Loops: `while-do`, `for-to-do`, `for-downto-do`
- Blocks: `begin-end`

### Operations
- Arithmetic: `+`, `-`, `*`, `/`, `%`
- Relational: `=`, `<>`, `<=`, `>=`, `<`, `>`
- Boolean: `and`, `or`, `not`
- Assignment: `:=`

### I/O Operations
- `read(variable)` - User input
- `write(expression)` - Console output

## Build & Run

Each task includes a `run.sh` script for compilation and execution:

```bash
chmod +x run.sh
./run.sh
```

### Manual Compilation
```bash
flex BGSASAS.l          # Generate lexer
yacc -d BGSASAS.y       # Generate parser
gcc lex.yy.c y.tab.c    # Compile
./a.out < input.txt     # Execute
```

## Task Details

### Task 1: Lexical Analyzer
**Files:** `BGSASAS.l`, `input.txt`

Tokenizes Pascal source code with case-insensitive keyword recognition and line tracking.

**Output Format:**
```
[Line Number]    [Lexeme]    [Token Type]
```

### Task 2: Syntax Analyzer  
**Files:** `BGSASAS.y`, `BGSASAS.l`

Validates program structure according to Pascal grammar rules using LALR(1) parsing.

**Output:** `Valid Sentence` or syntax error with line number

### Task 3: Semantic Analyzer
**Files:** Enhanced `BGSASAS.y` and `BGSASAS.l`

Performs type checking, variable declaration validation, and usage analysis.

**Features:**
- Multiple declaration detection
- Undeclared variable checking
- Type compatibility validation
- Uninitialized variable warnings

### Task 4: Code Generator
**Files:** Enhanced parser with TAC generation

Produces three-address code for all language constructs.

**Sample TAC Output:**
```
t0 = a + b
t1 = t0 * c
result = t1
```

### Task 5: Interpreter
**Files:** `test.l`, `test.y`

Complete interpreter with runtime execution and symbol table management.

**Features:**
- Direct program execution
- Runtime type checking
- Interactive I/O
- Symbol table display

## Type System

### Type Compatibility Rules

| Operation | Integer | Real | Boolean | Char |
|-----------|---------|------|---------|------|
| Arithmetic | ✓ | ✓ | ✗ | ✗ |
| Boolean | ✗ | ✗ | ✓ | ✗ |
| Relational | ✓ | ✓ | ✓ | ✓ |

### Assignment Rules
- Integer → Real: Allowed (promotion)
- Real → Integer: Error
- Boolean ↔ Arithmetic: Error

## Error Handling

The compiler provides comprehensive error detection:

- **Lexical Errors:** Invalid tokens
- **Syntax Errors:** Grammar violations with line numbers
- **Semantic Errors:** 
  - Undeclared variables
  - Multiple declarations
  - Type mismatches
  - Uninitialized variables

## Sample Program

```pascal
program Example;
var
  i: Integer;
begin
  i := 10;
  if i > 5 then
    write(i)
  else
    write(0);
end.
```

## Requirements

- **Flex** - Lexical analyzer generator
- **Yacc/Bison** - Parser generator
- **GCC** - C compiler
- **Unix/Linux** environment

### Installation

Ubuntu/Debian:
```bash
sudo apt-get install flex bison gcc
```

## Technical Implementation

- **Parsing:** LALR(1) with Yacc/Bison
- **Symbol Table:** Hash-based variable tracking
- **Type Checking:** Stack-based expression evaluation
- **Code Generation:** On-the-fly TAC generation
- **Memory Management:** Dynamic allocation for strings and arrays

## Notes

- Keywords are case-insensitive
- Variables must be declared before use
- No nested loops or conditionals (simplified for educational purposes)
- Arrays use static bounds checking
- The interpreter reads from `input.txt` by default

## Academic Context

This implementation follows CS F363 Compiler Construction course specifications, demonstrating all phases of compilation from source code to execution.