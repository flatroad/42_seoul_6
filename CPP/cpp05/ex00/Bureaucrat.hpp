#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define GRADE_HIGH 1
#define GRADE_UNDER 150

class Bureaucrat
{
	private :
		const std::string name_;
		int grade_;
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
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat&obj);
		~Bureaucrat();
		std::string get_name() const;
		int get_grade() const;
		void grade_increment();
		void grade_decrement();
};

std::ostream& operator<<(std::ostream& out_stream, const Bureaucrat& obj);

#endif