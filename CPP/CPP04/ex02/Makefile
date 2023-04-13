CC	=	c++
CPPFLAGE	=	-Wall -Wextra -Werror -std=c++98
CPPFILES	=	Animal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongCat.cpp \
				WrongAnimal.cpp \
				Brain.cpp \
				main.cpp
NAME	=	AnimalFarm
OBJS			=	$(CPPFILES:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGE) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGE) -c $? -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
	
.PHONY: all clean fclean re bonus
