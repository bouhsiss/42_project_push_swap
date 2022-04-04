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
CFLAGS = -Wall -Wextra -Werror -g
SRCS = ./srcs/actions.c ./tools/lst_tools.c ./tools/stack_tools.c ./srcs/push_swap.c ./tools/execution_tools.c ./tools/op_lst_tools.c ./tools/sort_tools.c ./srcs/small_sorter.c \
		./srcs/big_sorter.c ./srcs/err_check.c ./tools/search_tools.c ./srcs/parser.c

BONUS_NAME = checker
BONUS = ./srcs/actions.c ./tools/lst_tools.c ./tools/stack_tools.c ./tools/execution_tools.c ./tools/op_lst_tools.c ./tools/sort_tools.c ./srcs/small_sorter.c \
		./srcs/big_sorter.c ./srcs/err_check.c ./tools/search_tools.c ./checker_dir/checker.c ./checker_dir/get_next_line.c ./srcs/parser.c


$(LIB) :
	@echo "${GREEN}====================================="
	make -C $(LIB_DIR) --silent
	cp libft/$(LIB) ./

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	@echo "\n====== $(NAME) compiling finished ======"
	@echo "==========================================${NC}\n"

bonus : $(LIB)
	@echo "${MAGENTA}====================================="
	$(CC) $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	$(CC) $(CFLAGS) $(BONUS) $(LIB) -o $(BONUS_NAME)
	@echo "\n====== $(BONUS_NAME) compiling finished ======"
	@echo "==========================================\n${NC}"


all : $(NAME)
	
clean :
	@echo "${RED}====================================="
	rm -f *.o
	@echo "====== object files removed ======"
	@echo "===================================${NC}\n"

fclean : clean
	@echo "${YELLOW}====================================="
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(LIB)
	make fclean -C $(LIB_DIR) --silent
	rm -rf $(NAME).dSYM
	rm -rf $(BONUS_NAME).dSYM
	@echo "\n====== binary files removed ======="
	@echo "=====================================\n${NC}"

re : fclean all

.PHONY : all clean fclean re