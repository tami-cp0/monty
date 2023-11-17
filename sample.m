# these are valid operations for this interpreter:
# Feel free to modify
push # Pushes an integer onto the stack.
pint # Prints the value at the top of the stack followed by a new line.
pall # Prints all the values on the stack, starting from the top.
pop # Removes the top element of the stack.
swap # Swaps the top two elements of the stack.
nop # Does nothing.
add # Adds the top two elements of the stack.
div # Divides the second element by the top element of the stack.
mul # Multiplies the top two elements of the stack.
sub # Subtracts the top element from the second element on the stack.
mod # Computes the remainder of the division of the second element by the top element.
pstr # Prints the string starting from the top of the stack, terminated by a 0 (NULL) byte.
pchar # Prints the ASCII character of the top element of the stack.
rotl # Rotates the stack to the top (moves the top element to the bottom).
rotr # Rotates the stack to the bottom (moves the bottom element to the top).
stack # Sets the format of the data to a stack (LIFO).
queue # Sets the format of the data to a queue (FIFO).