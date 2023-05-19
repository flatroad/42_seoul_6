#ifndef FORM_HPP
#define FORM_HPP

#define GRADE_HIGH 1
#define GRADE_LOW 150

#include <iostream>
class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool check_sign;
		//서명등급
		const int grade_sign;
		//서명 실행 등급
		const int grade_exec;
		Form();
		Form& operator=(const Form& obj);

	public:
		Form(const std::string name, const int grade_sign, const int grade_exec);
		Form(const Form& obj);
		~Form();
		std::string getName() const;
		bool getCheckSign() const;
		int getGradeSign() const;
		int getGradeExec() const;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw(); 
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw(); 
		};
		void beSigned(const Bureaucrat& bureaucrat);
};
std::ostream& operator <<(std::ostream& out_stream, const Form& form);
#endif