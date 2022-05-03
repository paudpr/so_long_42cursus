NAME = so_long

OBJ_PATH = objects
SRC_PATH = sources
INC_PATH = includes
LBFT_PATH = libft

LDFLAGS = -L $(LBFT_PATH)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

CFLAGS += -I $(INC_PATH) -I $(LBFT_PATH)

LDLIBS = -lft

SRCS = main.c \
		map_main.c \
		draw_map.c \
		check_map.c \
		def_mario.c \
		utils.c \
		so_long.c \
		hooks.c \


OBJS_NAME = $(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LBFT_PATH)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS) -lmlx -framework OpenGL -framework AppKit

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH): 
	mkdir -p $(OBJ_PATH) 2> /dev/null

clean:
	make fclean -C $(LBFT_PATH)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean