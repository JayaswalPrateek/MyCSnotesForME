// in code editor the linter checks if an opening bracket in a expression is closed before the expression ends. This operation uses Stack and is called
// check for balanced parathesis
// every opening bracket should have a closing one so that it is balanced and expression is valid
// saying number of opeing brackets should be equal to nouber of closing is incomplete as )a+b( or [(]) is invalid
// other rules:
// an opening bracket should have a closing one to its right
// a bracket can be closed only if all the brackets opened inside it are closed
// last unclosed should be closed first
// [()()]
// scan from left to right
// if opening bracket add it to the list and if closing found then remove the topmost closing symbol in the list
// at the end the stack should be empty
