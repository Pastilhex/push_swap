NAME = push_swap

NAME_BONUS = checker

#LIB = mini_libft/mini_libft.a

CC = cc

SRC	= $(wildcard *.c)

SRC_BONUS = $(wildcard bonus/*.c)

OBJS	= $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

all:
	@echo "Compiling..."
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

bonus:
	$(CC) $(SRC_BONUS) $(CFLAGS) -o $(NAME_BONUS)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME_BONUS) a.out

re: fclean all

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME BONUS	: $(NAME_BONUS)\n"
	@printf "CC		: $(CC)\n"
	@printf "FLAGS		: $(CFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "SRC BONUS	: $(SRC_BONUS)\n"

PHONY: show fclean bonus clean all