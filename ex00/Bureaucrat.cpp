#include "Bureaucrat.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

Bureaucrat::Bureaucrat(): _name("UnamedBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::increaseGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decreaseGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}
