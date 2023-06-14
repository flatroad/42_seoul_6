#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	try
	{
		this.
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

void Bureaucrat::incrementGrade()
{
	if (grade + 1 > GRADE_LOW)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::decrementGrade()
{
	if (grade - 1 < GRADE_HIGH)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Bureaucrat] Grade too low exception");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Bureaucrat] Grade too high exception");
}

std::ostream& operator <<(std::ostream& out_stream, const Bureaucrat& bureaucrat){
	out_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << '\n';
	return (out_stream);
}