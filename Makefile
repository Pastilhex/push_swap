NAME = push_swap

NAME_BONUS = checker

CC = cc

SRC =	src/push_swap.c \
		src/count_steps_utils.c \
		src/count_steps.c \
		src/finish.c \
		src/list_big.c \
		src/list_small.c \
		src/unsorted.c \
		src/utils_a.c \
		src/utils_b.c \
		src/utils_c.c \
		src/utils_d.c \
		src/ra.c \
		src/rb.c \
		src/rr.c \
		src/rra.c \
		src/rrb.c \
		src/rrr.c \
		src/sa.c \
		src/sb.c \
		src/ss.c \
		src/pa.c \
		src/pb.c

SRC_BONUS = bonus/checker.c \
			bonus/finish.c \
			bonus/ft_atoll.c \
			bonus/utils_a.c \
			bonus/utils_b.c \
			bonus/utils_c.c \
			bonus/utils_d.c \
			bonus/ra.c \
			bonus/rb.c \
			bonus/rr.c \
			bonus/rra.c \
			bonus/rrb.c \
			bonus/rrr.c \
			bonus/sa.c \
			bonus/sb.c \
			bonus/ss.c \
			bonus/pa.c \
			bonus/pb.c \
			bonus/get_next_line/get_next_line.c \
			bonus/get_next_line/get_next_line_utils.c

OBJS	= $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

all:
	@echo "Compiling..."
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

bonus: all
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