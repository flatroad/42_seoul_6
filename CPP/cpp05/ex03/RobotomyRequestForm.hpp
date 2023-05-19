#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		virtual void execute(Bureaucrat const & executor) const;
    std::string getTarget()const;
};

#endif