#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string target_;
	public :
		RobotomyRequestForm(const char *target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		virtual ~RobotomyRequestForm();
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

#endif