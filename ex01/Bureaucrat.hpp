#pragma once

#include <string>
#include <exception>

class Form;

class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char *what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();
	void signForm(Form& form) const;

private:
	const std::string _name;
	int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);
