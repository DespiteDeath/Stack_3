#include "stack.hpp"

void foo_push() {
	cout << endl << "Start push" << endl;
	Stack<int> IntArr;
	for(int i = 0; i < 10; i++) { IntArr.push(i*2); }

	cout << "RESULT\t";
	for(size_t j = 0; j < IntArr.count(); j++) { cout << IntArr[j] << " "; }
	cout << endl << endl;
}

int main() {
	foo_push();
}
