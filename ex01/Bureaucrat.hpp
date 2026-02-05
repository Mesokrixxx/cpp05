#pragma once

#include <string>

class Bureaucrat {
public:
	std::exception GradeTooHighException;
	std::exception GradeTooLowException;

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

private:
	const std::string _name;
	int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bur);
