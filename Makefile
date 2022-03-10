NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = actions.c lst_tools.c stack_tools.c push_swap.c op_tools.c op_lst_tools.c sort_tools.c small_sorter.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	   $(CC) $(CFLAGS) $< -c

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f push_swap

re : fclean all

.PHONY : all clean fclean re