NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): megaphone.cpp
	$(CC) $(CFLAGS) megaphone.cpp -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all