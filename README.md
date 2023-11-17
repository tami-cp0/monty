# Stacks, Queues - LIFO, FIFO Monty Interpreter

## Description
This project revolves around the development of a **C-based** Monty interpreter, focusing on implementing fundamental opcodes for both `Stacks` (Last In, First Out - LIFO) and `Queues` (First In, First Out - FIFO).

The interpreter processes Monty byte code instructions to perform basic stack and queue operations.
> [bf](./bf) is a sub-directory used for learning basic operations in `brainfuck` programming language.

## Installation and Usage
To install, compile and run the project, clone the repository using the following command:
```
git clone https://github.com/Tamilore-0/monty.git
```
Compile the code using the following gcc command:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```
Run:
```
./monty <file>
```
Replace <file> with the path to the Monty byte code file.
***Ensure `<file>` contains valid monty opcodes in the bytecode file.***
***NOTE:*** The program accepts only a file as an argument and does not run in an interactive mode.

### Contribution
This project is part of the Software Engineering program at [ALX Africa](https://www.alxafrica.com/), Contributions will be well appreciated.
