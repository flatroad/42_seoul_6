#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int sign_lv, const int exec_lv) : name_(name), check_sign_(false), sign_lv_(sign_lv), exec_lv_(exec_lv)
{
	try
	{
		if (sign_lv_ > GRADE_LOW || exec_lv_ > GRADE_LOW)
			throw Form::GradeTooLowException();
		else if (sign_lv_ < GRADE_HIGH || exec_lv_ < GRADE_HIGH)
			throw Form::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw (3);
	}
}

Form::Form(const Form& obj) : name_(obj.getName()), 






















Form::Form(const Form& obj)
	:	name(obj.getName()), check_sign(obj.getCheckSign()), grade_sign(obj.getGradeSign()), grade_exec(obj.getGradeExec())
{
	std::cout << "[Form] Copy constructor" << '\n';
}

Form::~Form() {
	std::cout << "[Form] Destructor" << '\n';
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
