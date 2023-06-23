#include "AForm.hpp"

AForm::AForm(const std::string name, int sign_lv, int exec_lv) : name_(name)
{
	try
	{
		if (sign_lv < GRADE_HIGH || exec_lv < GRADE_HIGH)
			throw (AForm::GradeTooHighException());
		if (sign_lv > GRADE_LOW || exec_lv > GRADE_LOW)
			throw (AForm::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw (3);
	}
	this->exec_lv_ = exec_lv;
	this->sign_lv_ = sign_lv;
}

AForm::AForm(AForm& obj) : name_(obj.get_name()), check_sign_(false), sign_lv_(obj.get_sign_lv()), exec_lv_(obj.get_exec_lv()){};

AForm::~AForm(){}

const std::string AForm::get_name() const
{
	return (this->name_);
}

bool AForm::get_check_sign() const
{
	return(this->check_sign_);
}

int AForm::get_sign_lv() const
{
	return(this->sign_lv_);
}

int AForm::get_exec_lv() const
{
	return (this->exec_lv_);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("[AForm] grade over high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("[AForm] grade over low");
}

void AForm::beSigned(Bureaucrat& obj)
{

	if (this->sign_lv_ < obj.get_grade())
		throw (AForm::GradeTooLowException());
	this->check_sign_ = true;
}

std::ostream& operator<<(std::ostream& out_stream, const AForm& obj)
{
	out_stream << "docu_name : "<< obj.get_name() << std::endl;
	out_stream << "sign_lv : " << obj.get_sign_lv() << std::endl;
	out_stream << "exec_lv : " << obj.get_exec_lv() << std::endl;
	std::string sign = "";
	if (obj.get_check_sign())
		sign.append("true");
	else
		sign.append("false");

	out_stream << "check sign : " << sign << std::endl;
	return (out_stream);
}