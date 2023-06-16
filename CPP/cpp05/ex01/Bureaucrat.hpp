#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#define GRADE_HIGH 1
#define GRADE_LOW 150

class Bureaucrat {
 private:
	const std::string name;
	int grade;
	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(); 
	};
 public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	std::string getName()const;
	int getGrade()const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator <<(std::ostream& out_stream, const Bureaucrat& bureaucrat);

#endif