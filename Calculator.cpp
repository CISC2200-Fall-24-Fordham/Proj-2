#include "Calculator.hpp"

/**
 * @brief Calculate the result of the postfix expression
 * 
 * @param[in] postfixStk The stack containing the postfix expression
 * @return The result of the calculation as a BigInt
 * 
 * @pre The postfixStk is a valid postfix expression
 * @post The postfixStk is empty
 * 
 * Some pseudo code to help you get started:
 * 
 *      Create a stack to store the result
 *      While the postfixStk is not empty:
 *          Pop the top element
 *          If it is a number, push it to the result stack
 *          If it is an operator, pop two elements from the result stack
 *              Apply the operator and push the result back to the result stack
 *      The final result is the only element in the result stack
 */
ds::BigInt ds::Calculator::calculate(std::stack<ds::Token> &postfixStk)
{
    // TODO: Implement the function
    return ds::BigInt("123");
}