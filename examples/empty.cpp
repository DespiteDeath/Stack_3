#include "stack.hpp"

void foo_empty() {
	try {
		cout << endl << "Start empty" << endl;
		Stack<char> CharArr;

		char slovo[] = "SREHTORB_NINIHSREV"; 

		for(int i = 0; i < sizeof(slovo); i++) { CharArr.push(slovo[i]); }

		cout << "RESULT\t";
		while(!CharArr.empty()) {
			cout << CharArr.pop() << " ";
		}
		cout << endl << endl;

	} catch(const std::exception& e) {
		cout << e.what() << endl;
	}
}

int main() {
	foo_empty();
}
