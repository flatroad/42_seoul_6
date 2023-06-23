NAME := Bureaucrat
CXX := c++
CXXFLAGS := -Wextra -Werror -Wall -std=c++98
SRCS := main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp
OBJS := $(SRCS:%.cpp=%.o)
RM := rm -f

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)
	$(RM) target1

re :
	make fclean
	make all

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@

.PHONY: all re clean fclean