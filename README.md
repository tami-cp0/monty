# Stacks, Queues - LIFO, FIFO Monty Interpreter

## Description
This project revolves around the development of a **C-based** Monty interpreter, focusing on implementing fundamental opcodes for both `Stacks` (Last In, First Out - LIFO) and `Queues` (First In, First Out - FIFO).

The interpreter processes Monty byte code instructions to perform basic stack and queue operations.
> [bf](./bf) is a sub-directory used for learning basic operations in [`brainfuck`](https://en.wikipedia.org/wiki/Brainfuck) programming language.

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
Replace <file> with the path to the Monty byte code <file>.
***Ensure `<file>` contains valid monty opcodes in the bytecode file.***
> **NOTE:** The program accepts only a file as an argument and does not run in an interactive mode.

## Operations
> These are the current implemented functionalities:

1. `push` - Pushes an integer onto the stack.
2. `pint` - Prints the value at the top of the stack followed by a new line.
3. `pall` - Prints all the values on the stack, starting from the top.
4. `pop` - Removes the top element of the stack.
5. `swap` - Swaps the top two elements of the stack.
6. `nop` - Does nothing.
7. `add` - Adds the top two elements of the stack.
8. `div` - Divides the second element by the top element of the stack.
9. `mul` - Multiplies the top two elements of the stack.
10. `sub` - Subtracts the top element from the second element on the stack.
11. `mod` - Computes the remainder of the division of the second element by the top element.
12. `pstr` - Prints the string starting from the top of the stack, terminated by a 0 (NULL) byte.
13. `pchar` - Prints the ASCII character of the top element of the stack.
14. `rotl` - Rotates the stack to the top (moves the top element to the bottom).
15. `rotr` - Rotates the stack to the bottom (moves the bottom element to the top).
16. `stack` - Sets the format of the data to a stack (LIFO).
17. `queue` - Sets the format of the data to a queue (FIFO).

##
This README should give potential contributors or users a better understanding of the knowledge required to work with my ***monty*** project.

e-mail: findtamilore@gmail.com

> Feel free to use, modify, and distribute it without any restriction. I appreciate, but don't require, acknowledgement in derivative works.