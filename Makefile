SRCS	=  push_swap.c checker.c lst_funcs.c moves.c moves2.c sort_list.c sort_stacks.c init_a_to_b.c init_b_to_a.c sorting_utils.c 

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

LIB		= libftprintf.a

all: $(NAME)
	clear

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a .

clean:
	rm -rf $(OBJS) $(LIB)
	make clean -C ./ft_printf 

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./ft_printf 

re: fclean all