NAME_PROG = Zombie
NAME_FILE = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
NAME_OBJS = $(NAME_FILE:.cpp=.o)
COMP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic


.cpp.o:
	$(COMP) $(FLAGS) -c $< -o $@

all : $(NAME_PROG)

$(NAME_PROG): $(NAME_OBJS)
	$(COMP) $(FLAGS) $(NAME_OBJS) -o $(NAME_PROG)

clean :
	rm -rf $(NAME_OBJS)

fclean : clean
	rm -rf $(NAME_PROG)

re: fclean all