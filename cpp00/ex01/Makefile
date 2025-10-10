NAME_PROG = phonebook
NAME_FILE = PhoneBook.cpp Contact.cpp
NAME_OBJS = $(NAME_FILE:.cpp=.o)
COMP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic


.cpp.o:
	$(COMP) $(FLAGS) -c $< -o $@

all : $(NAME_PROG)

$(NAME_PROG): $(NAME_OBJS)
	$(COMP) $(FLAGS) $(NAME_OBJS) main.cpp -o $(NAME_PROG)

clean :
	rm -rf $(NAME_OBJS)

fclean : clean
	rm -rf $(NAME_PROG)

re: fclean all