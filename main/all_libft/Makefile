# **************************************************************************** #
#                                  Makefile                                   #
# **************************************************************************** #

# === Basic settings ===
NAME        := libft.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iinclude

# === Directories ===
SRC_DIR     := src
OBJ_DIR     := obj
INCLUDE_DIR := include

# === Source files ===
SRC_FILES := $(wildcard $(SRC_DIR)/libft/*.c) \
             $(wildcard $(SRC_DIR)/ft_printf/*.c) \
             $(wildcard $(SRC_DIR)/gnl/*.c)

OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# === Rules ===
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
