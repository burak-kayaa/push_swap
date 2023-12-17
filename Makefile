SRCS	=  push_swap.c checker.c lst_funcs.c moves.c moves2.c sort_list.c sort_stacks.c init_a_to_b.c init_b_to_a.c sorting_utils.c 

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

LIB		= libft.a

all: $(NAME)
	clear

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C ./libft
	cp ./libft/libft.a .

clean:
	rm -rf $(OBJS) $(LIB)
	make clean -C ./libft 

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft 

re: fclean all