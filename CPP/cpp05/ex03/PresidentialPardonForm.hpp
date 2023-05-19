#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		virtual void execute(Bureaucrat const & executor) const;
    std::string getTarget()const;
};

#endif
