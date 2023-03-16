CC	=	g++
CPPFLAGE	=	-Wall -Wextra -Werror -std=c++98
CPPFILES	=	Contact_insert.cpp \
				Contact_search.cpp \
				PhoneBook_add.cpp \
				PhoneBook_search.cpp \
				PhoneBook_set.cpp \
				PhoneBook_exit.cpp \
				main.cpp
NAME	=	PhoneBook
OBJS			=	$(CPPFILES:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGE) $(OBJS) -o $@

%.o: %.c
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
