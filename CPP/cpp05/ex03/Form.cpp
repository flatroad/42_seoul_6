#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("none"), check_sign(false), grade_sign(1), grade_exec(1) {
	std::cout << "[Form] Default constructor" << '\n';
}

Form::Form(const std::string name, const int grade_sign, const int grade_exec) 
	: name(name), check_sign(false), grade_sign(grade_sign), grade_exec(grade_exec){
		std::cout << "[Form] constructor" << '\n';
		if (grade_sign > GRADE_LOW || grade_exec > GRADE_LOW)
			throw Form::GradeTooLowException();
		else if (grade_sign < GRADE_HIGH || grade_exec < GRADE_HIGH)
			throw Form::GradeTooHighException();
}

Form::Form(const Form& obj)
	:	name(obj.getName()), check_sign(obj.getCheckSign()), grade_sign(obj.getGradeSign()), grade_exec(obj.getGradeExec())
{
	std::cout << "[Form] Copy constructor" << '\n';
}

Form::~Form() {
	std::cout << "[Form] Destructor" << '\n';
}

Form& Form::operator=(const Form& obj) {
	std::cout << "[Form] Copy assignment operator" << '\n';
	this->check_sign = obj.getCheckSign();
	return (*this);
}


std::string Form::getName() const{
	return (this->name);
}

bool Form::getCheckSign() const{
	return (this->check_sign);
}

int Form::getGradeSign() const{
	return (this->grade_sign);
}

int Form::getGradeExec() const{
	return (this->grade_exec);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("[Form] Grade too low exception");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("[Form] Grade too high exception");
}

std::ostream& operator <<(std::ostream& out_stream, const Form& form){
	out_stream << form.getName() << ", sign " << (form.getCheckSign() == false ? "false" : "true") << ", grade_sign " \
		 << form.getGradeSign() << ", grade_exec " << form.getGradeExec() << ".\n";
	return (out_stream);
}

void Form::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > this->grade_sign)
		throw Form::GradeTooLowException();
	else
		this->check_sign = true;
}