#include <iostream>
#include <string>
#include "queue.h"
#include "queue.cpp"

using namespace std;

int main() {
	queue<int> test_queue;
	bool repeat = true;
	int user_input;
	char char_input;

	do {
		cout << "Please enter an integer to enter into the queue\n";
		cin >> user_input;
		test_queue.push(user_input);
		cout << "Front of queue is currently: " << test_queue.front() << "\n";
		cout << "Would you like to enter another integer? y/n\n";
		cin >> char_input;
		if (char_input == 'y' || char_input == 'Y')
			repeat = true;
		else
			repeat = false;
	} while (repeat == true);

	cout << "\nFront of queue willed be popped.\nRemoved item: " << test_queue.pop() << "\n\n";
	if (test_queue.empty()) {
		cout << "Queue is now empty.\n";
	}
	else {
		cout << "Queue is not empty.\n";
		cout << "Current front of queue: " << test_queue.front() << "\n";
	}
	cout << "Size of queue: " << test_queue.size() << "\n";

	return 0;
}