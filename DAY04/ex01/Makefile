# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

# Files
SRCS = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = Animals

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re