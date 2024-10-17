NAME := libft.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := lib42
GC_DIR := gc
GNL_DIR := gnl
PRINTF_DIR := printf
OBJ_DIR := obj

SRC_FILES := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
    ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
    ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
    ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
    ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
    ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

B_FILES := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

GC_FILES := gc_malloc.c
GNL_FILES := get_next_line.c get_next_line_utils.c
PRINTF_FILES := ft_printf.c ft_printf_dec.c ft_printf_char.c ft_printf_hex.c ft_printf_str.c ft_printf_unsigned_dec.c ft_printf_ptr.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES)) $(addprefix $(GC_DIR)/, $(GC_FILES)) $(addprefix $(GNL_DIR)/, $(GNL_FILES)) $(addprefix $(PRINTF_DIR)/, $(PRINTF_FILES))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o) $(GC_FILES:.c=.o) $(GNL_FILES:.c=.o) $(PRINTF_FILES:.c=.o))
OBJ_B := $(addprefix $(OBJ_DIR)/, $(B_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GC_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
    ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
    ar -rcs $(NAME) $(OBJ) $(OBJ_B)

clean:
    rm -rf $(OBJ_DIR)

fclean: clean
    rm -f $(NAME)

re: fclean all