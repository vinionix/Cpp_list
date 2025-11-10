NAME_PROG = replace
NAME_FILE = main.cpp Replace.cpp
NAME_OBJS = $(NAME_FILE:.cpp=.o)
COMP = g++
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

all : $(NAME_PROG)

$(NAME_PROG): $(NAME_OBJS)
	$(COMP) $(FLAGS) $(NAME_OBJS) -o $(NAME_PROG)

clean :
	rm -rf $(NAME_OBJS)

fclean : clean
	rm -rf $(NAME_PROG)

re: fclean all

.PHONY: all clean fclean re