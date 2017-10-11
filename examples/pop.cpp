#include "stack.hpp"

void foo_pop() {
	try {
		cout << endl << "Start pop" << endl;
		Stack<double> DoubleArr;
		for(int i = 0; i < 10; i++) { DoubleArr.push(double(i)); }

		cout << "RESULT\t";
		for(int j = 0; j < 10; j++) 
		{ 
			DoubleArr.pop()
			cout << DoubleArr.top() << " "; 
					    }
		cout << endl << endl;

	} catch(const std::exception& e) {
		cout << e.what() << endl;
	}
}

int main() {
	foo_pop();
}
