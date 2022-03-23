NAME = push_swap
CC = gcc
LIB = libft.a
LIB_DIR = libft/
CFLAGS = -Wall -Wextra -Werror -g
SRCS = actions.c lst_tools.c stack_tools.c push_swap.c execution_tools.c op_lst_tools.c sort_tools.c small_sorter.c \
		big_sorter.c err_check.c search_tool.c
OBJS = $(SRCS:.c=.o)

BONUS_NAME = checker
BONUS = actions.c lst_tools.c stack_tools.c execution_tools.c op_lst_tools.c sort_tools.c small_sorter.c \
		big_sorter.c err_check.c search_tool.c checker.c 

BONUS_O = $(BONUS:.c=.o) 


%.o : %.c
	   $(CC) $(CFLAGS) $< -c

$(LIB) : 
	make -C $(LIB_DIR) --silent
	cp libft/$(LIB) ./

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================\n"

bonus : $(BONUS_O) $(LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	$(CC) $(CFLAGS) $(BONUS) -o $(BONUS_NAME)
	@echo "\n====== $(BONUS_NAME) compiling finished ======"
	@echo "==========================================\n"


all : $(NAME)
	
clean :
	rm -f $(OBJS)
	@echo "\n====== object files removed ======"
	@echo "===================================\n"

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)
	make fclean -C $(LIB_DIR) --silent
	rm -rf $(NAME).dSYM
	@echo "\n====== binary files removed ======="
	@echo "=====================================\n"

re : fclean all

.PHONY : all clean fclean re