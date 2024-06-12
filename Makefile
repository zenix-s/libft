# # DIRECTORIES
SRCP = ./src/
SRC = $(wildcard $(SRCP)**/*.c)
OBJ = $(SRC:.c=.o)


# VARIABLES
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a
RM = rm -f

# RULES

$(OBJ): %.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "libft.a created"

all: $(NAME)


clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re

