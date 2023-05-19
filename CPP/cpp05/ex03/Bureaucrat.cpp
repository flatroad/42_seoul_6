#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("none"), grade(150) {
	std::cout << "[Bureaucrat] Default constructor" << '\n';
}

Bureaucrat::Bureaucrat(const std::string& name) : name(name), grade(150) {
	std::cout << "[Bureaucrat] constructor" << '\n';
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	std::cout << "[Bureaucrat] constructor" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) :name(obj.getName()), grade(obj.getGrade()) {
	std::cout << "[Bureaucrat] Copy constructor" << '\n';
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat] Destructor" << '\n';
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	std::cout << "[Bureaucrat] Copy Copy assignment operator" << '\n';
	this->grade = obj.getGrade();
	return (*this);
}

std::string Bureaucrat::getName()const
{
	return (this->name);
}

int Bureaucrat::getGrade()const
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

void Bureaucrat::signForm(Form& form)const{
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

void Bureaucrat::executeForm(Form const & form){
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "== [Bureaucrat] executeForm fail ==\nException message : " << e.what() << '\n';
	}
	catch(const std::string& e)
	{
		std::cerr << "== [Bureaucrat] executeForm fail ==\nException message : " << e << '\n';
	}
	
}
