#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	try
	{
		if (this->grade > GRADE_LOW)
			throw (Bureaucrat::GradeTooLowException());
		if (this->grade < GRADE_HIGH)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw (1);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName()), grade(obj.getGrade()){}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > GRADE_LOW)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < GRADE_HIGH)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade over low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade over high");
}

std::ostream& operator <<(std::ostream& out_stream, const Bureaucrat& bureaucrat){
	out_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (out_stream);
}