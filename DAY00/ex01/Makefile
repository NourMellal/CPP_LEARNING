NAME = phonebook
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98


SRC = contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all