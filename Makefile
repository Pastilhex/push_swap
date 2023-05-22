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

SRC_BONUS = bonus/b_checker.c \
			bonus/b_finish.c \
			bonus/b_ft_atoll.c \
			bonus/b_list_small.c \
			bonus/b_utils_a.c \
			bonus/b_utils_b.c \
			bonus/b_utils_c.c \
			bonus/b_utils_d.c \
			bonus/b_ra.c \
			bonus/b_rb.c \
			bonus/b_rr.c \
			bonus/b_rra.c \
			bonus/b_rrb.c \
			bonus/b_rrr.c \
			bonus/b_sa.c \
			bonus/b_sb.c \
			bonus/b_ss.c \
			bonus/b_pa.c \
			bonus/b_pb.c \
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