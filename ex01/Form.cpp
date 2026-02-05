#include "Form.hpp"

static int checkGrade(int grade) {
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	return grade;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "(Form) Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "(Form) Grade too low";
}

Form::Form(): 
		_name("DefaultForm"), _signed(false), 
		_grade2sign(150), _grade2exec(150) {

}

Form::Form(const std::string& name, int grade2sign, int grade2exec):
		_name(name), _signed(false),
		_grade2sign(checkGrade(grade2sign)), 
		_grade2exec(checkGrade(grade2exec)) {
}

Form::Form(const Form& other):
		_name(other._name), _signed(other._signed),
		_grade2sign(other._grade2sign), _grade2exec(other._grade2exec) {

}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getGrade2Sign() const {
	return _grade2sign;
}

int Form::getGrade2Exec() const {
	return _grade2exec;
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > _grade2sign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << form.getName() << ": signed: " << form.isSigned()
		<< ", grade to sign: " << form.getGrade2Sign()
		<< ", grade to execute: " << form.getGrade2Exec();
	return out;
}
