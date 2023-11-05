#include <iostream>
#include "ExpressionManager.h"

/**Checks if a given string has balanced parantheses.
	@param input_string String to be evaluated
	@return True if string is balanced, false if not balanced*/
bool ExpressionManager::balanced_parantheses(std::string input_string) {
	bool is_balanced = true;

	for (int i = 0; i < input_string.length(); i++) {
		if (input_string[i] == '(' || input_string[i] == '[' || input_string[i] == '{')
			paren_stack.push(input_string[i]);

		else if (input_string[i] == ')') {
			if (paren_stack.empty() != true && paren_stack.top() == '(')
				paren_stack.pop();
			else {
				is_balanced = false;
			}
		}

		else if (input_string[i] == ']') {
			if (paren_stack.empty() != true && paren_stack.top() == '[')
				paren_stack.pop();
			else {
				is_balanced = false;
			}
		}

		else if (input_string[i] == '}') {
			if (paren_stack.empty() != true && paren_stack.top() == '{')
				paren_stack.pop();
			else {
				is_balanced = false;
			}
		}
	}

	if (paren_stack.empty())
		return is_balanced;
	else
		return false;
}

/*Converts inputted string from infix to postfix. Stores postfix string in class variable
expression. Outputs error message if expression is invalid, and postfix string otherwise.
	@param input_string String to be modified*/
void ExpressionManager::infix_to_postfix(std::string input_string) {
	if (not balanced_parantheses(input_string))
		std::cout << "Expression is invalid, parantheses must be balanced.\n";
	else {
		for (int i = 0; i < input_string.length(); i++) {
			//Low precedence operators
			if (input_string[i] == '+' || input_string[i] == '-') {
				if (in_to_post_stack.empty() || in_to_post_stack.top() == '(' || in_to_post_stack.top() == '[' || in_to_post_stack.top() == '{')
					in_to_post_stack.push(input_string[i]);
				else {
					while (in_to_post_stack.top() != '(' && in_to_post_stack.top() != '[' && in_to_post_stack.top() != '{') {
						expression += in_to_post_stack.top();
						in_to_post_stack.pop();
					}
					in_to_post_stack.push(input_string[i]);
				}
			}
			//High precedence operators
			else if (input_string[i] == '*' || input_string[i] == '/' || input_string[i] == '%') {
				if (in_to_post_stack.empty() || in_to_post_stack.top() == '(' || in_to_post_stack.top() == '[' || in_to_post_stack.top() == '{')
					in_to_post_stack.push(input_string[i]);
				else {
					while (in_to_post_stack.top() != '(' && in_to_post_stack.top() != '[' && in_to_post_stack.top() != '{' && in_to_post_stack.top() != '+' && in_to_post_stack.top() != '-') {
						expression += in_to_post_stack.top();
						in_to_post_stack.pop();
					}
					in_to_post_stack.push(input_string[i]);
				}
			}
			//Open parantheses
			else if (input_string[i] == '(' || input_string[i] == '[' || input_string[i] == '{') {
				in_to_post_stack.push(input_string[i]);
			}
			//Close parantheses
			else if (input_string[i] == ')' || input_string[i] == ']' || input_string[i] == '}') {
				while (in_to_post_stack.top() != '(' && in_to_post_stack.top() != '[' && in_to_post_stack.top() != '{') {
					expression += in_to_post_stack.top();
					in_to_post_stack.pop();
				}
				in_to_post_stack.pop();
			}
			else
				expression += input_string[i];
		}
		while (not in_to_post_stack.empty()) {
			expression += in_to_post_stack.top();
			in_to_post_stack.pop();
		}
		std::cout << expression;
	}
}