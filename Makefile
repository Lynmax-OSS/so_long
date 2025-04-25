SRCS    = so_long.c ./src/*.c

OBJS    = $(SRCS:.c=.o)

NAME    = so_long

CC      = cc

# X11 path on Linux (common path)
X11_INC = /usr/include/X11
X11_LIB = /usr/lib

# MinilibX path (adjust these if needed)
MLX_INC = mlx_linux
MLX_LIB = mlx_linux

# Additional libraries needed
LIBS    = -lXext -lX11 -lm 

all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L. -lmlx -L$(X11_LIB) -I$(MLX_INC) -I$(X11_INC) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(X11_INC) -I$(MLX_INC) -O3 -c $< -o $@

clean:
					$(RM) $(OBJS_DIR) so_long.o destroy_win.o
					$(MAKE) -C $(LIBFT_DIR) clean

fclean:				clean
					$(RM) $(NAME)
					$(MAKE) -C $(LIBFT_DIR) fclean

re:					fclean all

.PHONY:				fclean all re clean

# For MAC below

# NAME		=		so_long

# CC			=		cc

# CFLAGS		=		-g3 -Wall -Wextra -Werror

# RM			=		rm -rf

# LIBFT_DIR	=		./libft

# LIBFT		=		$(LIBFT_DIR)/libft.a

# MLX			=	 	libmlx.a

# MLX_FLAGS	= 		-I /opt/X11/include -L /opt/X11/lib -lX11 -lXext

# SRCS_DIR	=		./srcs

# SRCS		=		$(wildcard $(SRCS_DIR)/*.c) so_long.c

# OBJS_DIR	=		objs

# OBJS		=		$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# all:				$(NAME)

# $(NAME):			$(OBJS) $(LIBFT)
# 					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

# $(LIBFT):
# 					$(MAKE) -C $(LIBFT_DIR)

# $(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c | $(OBJS_DIR)
# 					$(CC) $(CFLAGS) -c $< -o $@

# $(OBJS_DIR)/so_long.o: so_long.c | $(OBJS_DIR)
# 					$(CC) $(CFLAGS) -c $< -o $@

# $(OBJS_DIR):
# 					mkdir -p $(OBJS_DIR)

# clean:
# 					$(RM) $(OBJS_DIR) so_long.o
# 					$(MAKE) -C $(LIBFT_DIR) clean

# fclean:				clean
# 					$(RM) $(NAME)
# 					$(MAKE) -C $(LIBFT_DIR) fclean

# re:					fclean all

# .PHONY:				fclean all re clean
