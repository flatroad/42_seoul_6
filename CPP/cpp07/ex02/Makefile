NAME := Array
CXX := c++
CXXFLAGS := -Wextra -Werror -Wall -std=c++98
SRCS := main.cpp \
		Array.cpp
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

re :
	make fclean
	make all

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@

.PHONY: all re clean fclean