// infix expressions are ones which have operator that performs binary operation in the middle of two operands
// when we add braces the evaluation gets precedences
// such infix expressions can be evaluated by using stack
// when one operator and 2 operands and no braces then no problem
// when 2 operator and 4 operands and no brace like a+b*c use DMAS
// brackets>exponents>mul=div>sub=add
// for many exp go right to left
// for  only mul and div in same exp go from L to R
// for  only add and sub in same exp go from L to R
// so many rules
// so people proposed  postfix and prefix notation

// prefix: 2-3 is - 2 3, p-q is - p q
// operator operand operand
// a+(b*c) is +a*bc
// (a+b)*c is +ab * c

// postfix: least costly to evaluate
// operand operand operator
// 2 3 -
// p q -
// abc*+ is a(bc*)+ is a+(b*c) is a+b*c
// abc+* is a(bc+)* is a*(b+c)
// ab+c* is (a+b)*c

/**
 * pseudo code for postfix evaluation
 * function that takes a string input
 * for loop runs till the len of string
 * if str(i) is operand push to stack
 * else if operator
 *      pop 2 operands and use operator
 *      push(result)
 *
 * after for loop ended the top of the stack gives the answer
 * so return top
 */
