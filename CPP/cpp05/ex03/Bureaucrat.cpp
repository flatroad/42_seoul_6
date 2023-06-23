#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	return ("Bureaucrat grade over low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade over high");
}

void Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name_ << " couldn’t sign " << obj.get_name() << " because " << e.what() << std::endl;
		throw (4);
	}
	std::cout << this->name_ << " signed " << obj.get_name() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->get_name() << " excuted " << form.get_name() << std::endl;
	}
	catch(const char *err)
	{
		std::cerr << this->get_name() << " fails to activate "  << form.get_name() << " : " << err << std::endl;
		throw (5);
	}
}

std::ostream& operator<<(std::ostream& out_stream, const Bureaucrat& bureaucrat){
	out_stream << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade() << "." << std::endl;
	return (out_stream);
}
