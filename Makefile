SRCS	=  push_swap.c checker.c lst_funcs.c moves.c moves2.c sort_list.c sort_stacks.c init_a_to_b.c init_b_to_a.c sorting_utils.c 

OBJS	= $(SRCS:.c=.o)

SRCSB	= bonus.c checker.c lst_funcs.c moves.c moves2.c sort_list.c sort_stacks.c init_a_to_b.c init_b_to_a.c sorting_utils.c 

OBJSB	= $(SRCSB:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

LIB		= libft.a

BONUS	= checker

all: $(NAME)
	clear

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C ./libft
	cp ./libft/libft.a .

bonus: $(OBJSB) $(LIB)
	$(CC) $(CFLAGS) $(OBJSB) $(LIB) -o $(BONUS)

clean:
	rm -rf $(OBJS) $(LIB)
	make clean -C ./libft 

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft 

re: fclean all