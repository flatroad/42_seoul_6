CC	=	c++
CPPFLAGE	=	-Wall -Wextra -Werror -std=c++98
CPPFILES	=	main.cpp \
				BitcoinExchange.cpp
NAME	=	btc
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
