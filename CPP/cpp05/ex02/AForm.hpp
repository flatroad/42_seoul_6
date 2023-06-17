#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>

#define GRADE_HIGH 1
#define GRADE_LOW 150

class Bureaucrat;

class AForm
{
	private :
		const std::string name_;
		bool check_sign_;
		int	sign_lv_;
		int exec_lv_;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};
	public :
		AForm(const std::string name, int sign_lv, int exec_lv);
		AForm(Form& obj);
		~Form();
		const std::string get_name() const;
		bool get_check_sign() const;
		int	get_sign_lv() const;
		int get_exec_lv() const;
		void beSigned(const Bureaucrat& obj);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out_stream, const Form& obj);

#endif