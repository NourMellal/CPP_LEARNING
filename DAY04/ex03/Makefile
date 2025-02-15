# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

# Files
SRCS = AMateria.cpp   Cure.cpp  ICharacter.cpp  MateriaSource.cpp Character.cpp  Ice.cpp   main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex03

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