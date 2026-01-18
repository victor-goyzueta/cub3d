GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = cub3d


CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CFLAGS += -I libft
CFLAGS += -I inc
CFLAGS += -I minilibx


LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx_Linux.a
MLX_FLAGS = -L minilibx -lmlx -lXext -lX11 -lm -lbsd

SRCS =	src/main.c							\
		src/parse/parse_cub.c				\
		src/parse/get_lines.c				\
		src/parse/find_map_start.c			\
		src/parse/find_map_start_utils.c	\
		src/parse/parse_map.c				\
		src/parse/map_check.c				\
		src/parse/map_check_utils.c			\
		src/parse/init_player.c				\
		src/play/hook_handlers.c			\
		src/play/update_player.c			\
		src/play/move_player.c				\
		src/play/raycast.c					\
		src/play/raycast_utils.c			\
		src/play/draw_textured_column.c		\
		src/utils/init_utils.c				\
		src/utils/set_utils.c				\
		src/utils/bool_utils.c				\
		src/utils/free_utils.c				\
		src/delete.c						\


OBJS = $(SRCS:src/%.c=objs/%.o)

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): objs $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)cub3d ready$(WHITE)"

$(LIBFT):
	@make --silent -C libft

$(MINILIBX):
	@make -C minilibx --silent > /dev/null 2>&1

objs:
	@mkdir -p objs

objs/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make --silent clean -C libft
	@make --silent clean -C minilibx > /dev/null 2>&1
	@rm -rf objs
	@echo "Objetcs files deleted."

fclean: clean
	@make --silent fclean -C libft
	@make --silent clean -C minilibx > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re
