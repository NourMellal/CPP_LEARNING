# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = human

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
