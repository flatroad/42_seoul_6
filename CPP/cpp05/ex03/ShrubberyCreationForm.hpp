#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#define ASCII_TREE "\
      @@      \n\
    @@@@@@    \n\
   @@@@@@@@   \n\
     |  |     \n\
     |  |     \n"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private :
		std::string target_;
	public :
		ShrubberyCreationForm(const char *target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		virtual ~ShrubberyCreationForm();
		std::string getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
};

#endif