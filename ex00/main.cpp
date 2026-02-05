#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	try {
		Bureaucrat b;

		std::cout << b << "\n";
		b.decreaseGrade();
		std::cout << b << "\n";
		b.increaseGrade();
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Catched an exception" << std::endl;
	}

	std::cout << "\n";
	try {
		Bureaucrat b("John", 3);

		for (int i = 0; i < 50; i++) {
			std::cout << b << "\n";
			b.increaseGrade();
		}
	} catch (std::exception& e) {
		std::cerr << "Catched an exception" << std::endl;
	}
	return 0;
}
