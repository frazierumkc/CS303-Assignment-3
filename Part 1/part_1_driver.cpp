#include <iostream>
#include "ExpressionManager.h"

using namespace std;

int main() {
	string user_input = "";
	ExpressionManager test_expression;
	cout << "Please input an infix expression to be converted to postfix, with no spaces.\n";
	cin >> user_input;
	cout << "\nPostfix conversion:\n";
	test_expression.infix_to_postfix(user_input);
	cout << "\n";
	return 0;
}