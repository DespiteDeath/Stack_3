#include "stack.hpp"

void foo_init();
void foo_push();
void foo_pop();
void foo_empty();

int main() {
	try {
		foo_init();
		foo_push();
		foo_pop();
		foo_empty();
		} 
	catch(std::exception &e) {
		cout << e.what() << endl;
	}

	return 0;
}
