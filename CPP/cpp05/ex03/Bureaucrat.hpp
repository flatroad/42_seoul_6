#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#define GRADE_HIGH 1
#define GRADE_LOW 150

class Form;

class Bureaucrat {
 private:
	const std::string name;
	int grade;
	Bureaucrat& operator=(const Bureaucrat& obj);
	Bureaucrat();

 public:
	Bureaucrat(const std::string& name);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(); 
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(); 
	};

	std::string getName()const;
	int getGrade()const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form)const;
	void executeForm(Form const & form);
};

std::ostream& operator <<(std::ostream& out_stream, const Bureaucrat& bureaucrat);

#endif