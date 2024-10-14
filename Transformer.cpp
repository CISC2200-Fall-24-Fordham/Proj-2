#include "Transformer.hpp"

/**
 * @brief Convert infix expression to postfix expression
 * 
 * @param[in] infix The infix expression
 * @return The postfix expression
 * 
 * @pre The infix expression is valid
 * @post The postfix expression is valid
 * 
 * Some pseudo code to help you get started:
 *      Create a stack to store the operators
 *      Create a string to store the result
 *      For each token in the infix expression:
 *          If the token is a number, add it to the result
 *          If the token is an operator:
 *              While the stack is not empty and the top of the stack has higher precedence:
 *                  Pop the top of the stack and add it to the result
 *              Push the current operator to the stack
 *          If the token is a left parenthesis, push it to the stack
 *          If the token is a right parenthesis:
 *             While the top of the stack is not a left parenthesis:
 *                  Pop the top of the stack and add it to the result
 *      
 */
std::stack<ds::Token> ds::InfixToPostfixTransformer::infixToPostfix(const std::vector<ds::Token> &infix)
{
    // TODO
    return std::stack<ds::Token>();
}