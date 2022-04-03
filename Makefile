RED = \033[0;31m
NC = \033[0m	
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

NAME = push_swap
CC = gcc
LIB = libft.a
LIB_DIR = libft/
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
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
	@echo "${GREEN}====================================="
	make -C $(LIB_DIR) --silent
	cp libft/$(LIB) ./

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================${NC}\n"

bonus : $(BONUS_O) $(LIB)
	@echo "${MAGENTA}====================================="
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	$(CC) $(CFLAGS) $(BONUS) $(LIB) -o $(BONUS_NAME)
	@echo "\n====== $(BONUS_NAME) compiling finished ======"
	@echo "==========================================\n${NC}"


all : $(NAME)
	
clean :
	@echo "${RED}====================================="
	rm -f $(OBJS)
	@echo "====== object files removed ======"
	@echo "===================================${NC}\n"

fclean : clean
	@echo "${YELLOW}====================================="
	rm -f $(NAME) $(BONUS_O) $(BONUS_NAME)
	rm -f $(LIB)
	make fclean -C $(LIB_DIR) --silent
	rm -rf $(NAME).dSYM
	rm -rf $(BONUS_NAME).dSYM
	@echo "\n====== binary files removed ======="
	@echo "=====================================\n${NC}"

re : fclean all

.PHONY : all clean fclean re