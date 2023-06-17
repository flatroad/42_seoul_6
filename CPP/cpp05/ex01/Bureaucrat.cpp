#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade)
{
	try
	{
		if (this->grade_ > GRADE_LOW)
			throw (Bureaucrat::GradeTooLowException());
		if (this->grade_ < GRADE_HIGH)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw (1);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name_(obj.getName()), grade_(obj.getGrade()){}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
	return (this->name_);
}

int Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void Bureaucrat::decrementGrade()
{
	if (this->grade_ + 1 > GRADE_LOW)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade_++;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade_ - 1 < GRADE_HIGH)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade_--;
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

void Bureaucrat::signForm(Form& form) const
{
	if (form.getCheckSign() == false)
	{
		try
		{
			form.beSigned(*this);
			std::cout << (*this) << " signed " << form;
		}
		catch(const std::exception& e)
		{
			std::cerr << (*this) << " couldn’t sign " << form << "because " <<  e.what() << '\n';
		}
	}
	else
		std::cout << form << "signed already true" << '\n';
}