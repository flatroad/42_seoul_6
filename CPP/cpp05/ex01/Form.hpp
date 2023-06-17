#ifndef FORM_HPP
#define FORM_HPP

#define GRADE_HIGH 1
#define GRADE_LOW 150

#include <iostream>
class Bureaucrat;

class Form {
	private:
		const std::string name_;
		bool check_sign_;
		const int sign_lv_;
		const int exec_lv_;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw(); 
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw(); 
		};

	public:
		Form(const std::string name, const int grade_sign, const int grade_exec);
		Form(const Form& obj);
		~Form();
		std::string getName() const;
		bool getCheckSign() const;
		int getSignLv() const;
		int getExecLv() const;
		void beSigned(const Bureaucrat& bureaucrat);
};
std::ostream& operator <<(std::ostream& out_stream, const Form& form);
#endif