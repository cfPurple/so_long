#####################################SO_LONG#####################################

NAME	= so_long

#####################################SRCS########################################

PATH_SRCS = srcs/

SRCS	= get_map.c checking.c direction.c travel.c init.c window.c 

MAIN	= srcs/main.c

vpath %.c $(PATH_SRCS)

###################################OBJS#########################################

PATH_OBJS = objs
OBJS	= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

################################COMPILATION####################################

INCLUDE	= -Ilibft -Iinclude -I minilibx-linux 

LINK	= libft/libft.a -L minilibx-linux/ -lmlx -lXext -lX11

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g3

##################################RULES#######################################

all:  libft $(NAME)

libft:
	${MAKE} -sC libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(MAIN) -o objs/main.o $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) objs/main.o $(INCLUDE) $(LINK) -g3 

$(OBJS) : $(PATH_OBJS)/%.o:%.c
		mkdir -p $(PATH_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -r $(PATH_OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)

re: fclean
		${MAKE}

.PHONY: all libft clean fclean re