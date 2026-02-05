#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
	std::cout << "Should fail because grade isn't right for form" << "\n";
	try {
		Bureaucrat b("John", 100);
		Form f("File1", 4645, 12);

		std::cout << "Bureaucrat: " << b << "\n";
		std::cout << "Form: " << f << "\n";
		b.signForm(f);
	} catch (std::exception& e) {
		std::cout << "Caught an exception: " << e.what() << "\n";
	}

	std::cout << "\nShould fail because grade isn't right for form" << "\n";
	try {
		Bureaucrat b("John", 100);
		Form f("File1", 12, 0);

		std::cout << "Bureaucrat: " << b << "\n";
		std::cout << "Form: " << f << "\n";
		b.signForm(f);
	} catch (std::exception& e) {
		std::cout << "Caught an exception: " << e.what() << "\n";
	}

	std::cout << "\nShould fail because grade isn't right for Bureaucrat" << "\n";
	try {
		Bureaucrat b("John", 4645);
		Form f("File1", 50, 50);

		std::cout << "Bureaucrat: " << b << "\n";
		std::cout << "Form: " << f << "\n";
		b.signForm(f);
	} catch (std::exception& e) {
		std::cout << "Caught an exception: " << e.what() << "\n";
	}

	std::cout << "\nForm shouldn't get signed" << "\n";
	try {
		Bureaucrat b("John", 100);
		Form f("File1", 50, 50);

		std::cout << "Bureaucrat: " << b << "\n";
		std::cout << "Form: " << f << "\n";
		b.signForm(f);
	} catch (std::exception& e) {
		std::cout << "Caught an exception: " << e.what() << "\n";
	}

	std::cout << "\nForm should be signed" << "\n";
	try {
		Bureaucrat b("John", 100);
		Form f("File1", 150, 150);

		std::cout << "Bureaucrat: " << b << "\n";
		std::cout << "Form: " << f << "\n";
		b.signForm(f);
	} catch (std::exception& e) {
		std::cout << "Caught an exception: " << e.what() << "\n";
	}
	return 0;
}
