ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

NAME = push_swap
CC = gcc
LIB = libft.a
LIB_DIR = libft/
CFLAGS = -Wall -Wextra -Werror -g
SRCS = actions.c lst_tools.c stack_tools.c push_swap.c execution_tools.c op_lst_tools.c sort_tools.c small_sorter.c \
		big_sorter.c err_check.c search_tools.c parser.c
OBJS = $(SRCS:.c=.o)

BONUS_NAME = checker
BONUS = actions.c lst_tools.c stack_tools.c execution_tools.c op_lst_tools.c sort_tools.c small_sorter.c \
		big_sorter.c err_check.c search_tools.c checker.c get_next_line.c parser.c

BONUS_O = $(BONUS:.c=.o) 


%.o : %.c
	   $(CC) $(CFLAGS) $< -c

$(LIB) : 
	make -C $(LIB_DIR) --silent
	cp libft/$(LIB) ./

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================\n"

bonus : $(BONUS_O) $(LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	$(CC) $(CFLAGS) $(BONUS) $(LIB) -o $(BONUS_NAME)
	@echo "\n====== $(BONUS_NAME) compiling finished ======"
	@echo "==========================================\n"


all : $(NAME)
	
clean :
	rm -f $(OBJS)
	@echo "====== object files removed ======"
	@echo "===================================\n"

fclean : clean
	rm -f $(NAME) $(BONUS_O) $(BONUS_NAME)
	rm -f $(LIB)
	make fclean -C $(LIB_DIR) --silent
	rm -rf $(NAME).dSYM
	rm -rf $(BONUS_NAME).dSYM
	@echo "\033[33mn====== binary files removed =======\033[33m"
	@echo "\033[33m=====================================\n\033[33m"

re : fclean all

.PHONY : all clean fclean re