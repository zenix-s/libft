# DIRECTORIES
SRCP = ./src/

SRCS = $(notdir $(wildcard $(SRCP)*.c))

SRC = $(addprefix $(SRCP), $(SRCS))

OBJ = $(SRC:.c=.o)


# VARIABLES
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a
LIB = ranlib
RM = rm -f

# RULES

# @$(CC) $(CFLAGS) -c  $< -o $@
$(OBJ): %.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(LIB) $(NAME)
	@echo "libft.a created"

all: $(NAME)

bonus: $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(LIB) $(NAME)
	@echo "libft.a created"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all	clean fclean re
