#variables
NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
SDIR = srcs/
LIB = libft
LRB = /usr/local/Cellar/readline/8.1.2
INC = include
INC_ALL = 	-I$(INC) \
			-I$(LIB) \
			-I$(LRB)/include
LINK = 	-L$(LRB)/lib -lreadline -L$(LIB) -lft\

#color
DEFCO = '\033[0m'
RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'
MAGENTA = '\033[0;35m'
CYAN = '\033[0;36m'

#sources
SRC_NAME = 	myshell_main.c \
			lexer.c \
			parser.c \
			expander.c \
			executor.c \
			exe_utils.c \
			exe_single.c \
			exe_signal.c \
			exe_pipex.c \
			buildins.c \
			init.c \
			cmdnode_utils.c \
			free_data.c \
			buildin/exe_cd.c \
			buildin/exe_echo.c \
			buildin/exe_env.c \
			buildin/exe_export.c \
			buildin/exe_pwd.c \
			buildin/exe_unset.c \
			parser_utils.c \


OBJS = $(addprefix $(SDIR), $(SRC_NAME:.c=.o))

all : $(NAME)

$(SDIR)%.o : $(SDIR)%.c
	@ $(CC) $(FLAGS) $(INC_ALL) -c $< -o $@

$(NAME) : $(OBJS)
	@ echo "$(YELLOW)Make libft.a library$(DEFCO)"
	@ make -C $(LIB)
	@ echo "$(GREEN)libft.a created$(DEFCO)"
	@ $(CC) $(FLAGS) $(OBJS) $(LINK) -o $(NAME)
	@ echo "$(GREEN)$(NAME) created$(DEFCO)"



clean:
	@ make clean -C $(LIB)
	@ echo "$(YELLOW)libft.a removed$(DEFCO)"
	@ rm $(SDIR)buildin/*.o
	@ rm $(SDIR)*.o
	@ echo "$(GREEN)Object files removed$(DEFCO)"

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIB)
	@ echo "$(GREEN)$(NAME) removed$(DEFCO)"

re: fclean all

.PHONY: all clean fclean res
