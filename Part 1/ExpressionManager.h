#ifndef EXPRESSIONMANAGER_H_
#define EXPRESSIONMANAGER_H_
#include <string>
#include <stack>

class ExpressionManager {
public:
	/**Checks if a given string has balanced parantheses.
		@param input_string String to be evaluated
		@return True if string is balanced, false if not balanced*/
	bool balanced_parantheses(std::string input_string);

	/*Converts inputted string from infix to postfix. Stores postfix string in class variable
	expression. Outputs error message if expression is invalid, and postfix string otherwise.
		@param input_string String to be modified*/
	void infix_to_postfix(std::string input_string);
private:
	std::string expression;
	std::stack<char> in_to_post_stack;
	std::stack<char> paren_stack;
};
/*Read an infix expression from the user.

Perform the Balanced Parentheses Check on the expression read.

{, }, (, ), [, ] are the only symbols considered for the check. All other characters can be ignored.

If the expression fails the Balanced Parentheses Check, report a message to the user that the
expression is invalid.

If the expression passes the Balanced Parentheses Check, convert the infix expression into a
postfix expression and display it to the user.

Operators to be considered are +, –, *, /, %.
*/

#endif
