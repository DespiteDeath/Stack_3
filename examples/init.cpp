#include "stack.hpp"

void foo_init() {
	try {
		cout << endl << "Init 3 Int-Arrays" << endl << endl;
		Stack<int> IntArrA;
		Stack<int> IntArrB;
		Stack<int> IntArrC = Stack<int>(100);

		cout << "Fill IntArrA arr" << endl << endl;
		for (int i = 0; i < 10; i++) {
			IntArrA.push(i);
		}

		cout << "Copy IntArrA into IntArrB..." << endl << endl;
		IntArrB = IntArrA;

		cout << "Clean IntArrA arr" << endl << "RESULT\t";
		while(!IntArrA.empty()) {
			cout << IntArrA.pop() << " ";
		}
		cout << endl << endl;

		cout << "Clean IntArrB arr" << endl << "RESULT\t";
		while(!IntArrB.empty()) {
			cout << IntArrB.pop() << " ";
		}
		cout << endl << endl;

	} catch(const std::exception& e) {
		cout << e.what() << endl;
	}
}

int main() {
	foo_init();
}
