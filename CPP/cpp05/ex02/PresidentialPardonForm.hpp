#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string target_;
	public :
		PresidentialPardonForm(const char *target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		virtual ~PresidentialPardonForm();
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

#endif