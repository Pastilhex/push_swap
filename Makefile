NAME = push_swap

NAME_BONUS = checker

CC = cc

SRC	= ./*.c

SRC_BONUS = $(wildcard bonus/*.c)

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

all:
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

bonus:
	$(CC) $(SRC_BONUS) $(CFLAGS) -o $(NAME_BONUS)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME_BONUS)

re: fclean all

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME BONUS	: $(NAME_BONUS)\n"
	@printf "CC		: $(CC)\n"
	@printf "FLAGS		: $(CFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "SRC BONUS	: $(SRC_BONUS)\n"

PHONY: show fclean bonus clean all