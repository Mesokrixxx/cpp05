#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
public:
	class GradeTooHighException : public std::exception {
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char *what() const throw();
	};

	Form();
	Form(const std::string& name, int grade2sign, int grade2exec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string& getName() const;
	bool isSigned() const;
	int getGrade2Sign() const;
	int getGrade2Exec() const;

	void beSigned(const Bureaucrat& bur);

private:
	const std::string _name;
	bool _signed;
	const int _grade2sign;
	const int _grade2exec;
};

std::ostream& operator<<(std::ostream& out, const Form& form);
