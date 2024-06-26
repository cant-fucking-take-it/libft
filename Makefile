SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
HDR_FILES = libft.h

SRC_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJ_BONUS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_BONUS))

TEST_SRCS = $(wildcard $(TEST_DIR)/test_*.c) $(TEST_DIR)/memutils.c $(TEST_DIR)/all.c
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c,$(TEST_BUILD)/%.o,$(TEST_SRCS))

TEST_EXECS = $(addprefix $(TEST_DIR)/,tests.o nulls.o bonus.o)

BUILD_DIR = build
TEST_DIR = tests
TEST_BUILD = $(TEST_DIR)/build

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

ARFLAGS = rcs

all: $(NAME)

.SECONDEXPANSION:
$(NAME): $$(OBJ_FILES) $(HDR_FILES)
	$(AR) $(ARFLAGS) $@ $?

bonus: OBJ_FILES += $(OBJ_BONUS)
bonus: $(NAME)

$(BUILD_DIR)/%.o: %.c $(HDR_FILES) Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

$(TEST_BUILD):
	mkdir -p $@ 

test: $(NAME) $(TEST_DIR)/tests.o Makefile

test_bonus: bonus $(TEST_DIR)/bonus.o $(TEST_DIR)/nulls.o Makefile

tests/tests.o: $(TEST_OBJS)
	$(CC) -o $@ -g $^ -I. -L. -lft -lbsd

tests/bonus.o tests/nulls.o: %.o:%.c
	$(CC) -o $@ -g $< -I. -L. -lft 

$(TEST_BUILD)/%.o: $(TEST_DIR)/%.c | $(TEST_BUILD)
	$(CC) $? -w -g -c -o $@ -I. -L. -lft -lbsd

clean reclean:
	rm -rf $(BUILD_DIR) $(TEST_BUILD)

fclean: clean
	rm -f $(NAME) $(TEST_EXECS)

re: fclean all reclean

rebonus: fclean bonus reclean

retest: fclean bonus test test_bonus 

info:
	$(info $(SRC_FILES))
	$(info $(SRC_BONUS))


.PHONY: all fclean reclean re test bonus rebonus info
