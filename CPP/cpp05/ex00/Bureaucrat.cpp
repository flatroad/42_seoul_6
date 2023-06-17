#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name)
{
	try
	{
		if (grade > GRADE_UNDER)
			throw (Bureaucrat::GradeTooLowException());
		if (grade < GRADE_HIGH)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw (1);
	}
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name_(obj.get_name()), grade_(obj.get_grade()){}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::get_name() const
{
	return (this->name_);
}

int Bureaucrat::get_grade() const
{
	return (this->grade_);
}

void Bureaucrat::grade_increment()
{
	--grade_;
	if (this->grade_ < GRADE_HIGH)
		throw Bureaucrat::GradeTooHighException();	
}

void Bureaucrat::grade_decrement()
{
	++grade_;
	if (this->grade_ > GRADE_UNDER)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade over under");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade over high");
}

std::ostream& operator<<(std::ostream& out_stream, const Bureaucrat& obj)
{
	out_stream << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << "." << std::endl;
	return (out_stream);
}
