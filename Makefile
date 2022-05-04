NAME = libftprintf.a
LIBFT_NAME = ./libft/libft.a
LIBFT_DIR = ./libft
SRC_DIR	= ./src
BONUS_SRC_DIR = ./bonus_src
OBJ_DIR = ./obj

CC = gcc
CFLAGS = -Werror -Wall -Wextra
INCFLAG	= -I ./include
DEPSFLAG = -MMD -MP

PRINTF_SRC 					= ft_printf.c ft_fmt_csper.c ft_fmt_diuxXp.c ft_printf_utils.c
PRINTF_OBJ					= $(PRINTF_SRC:.c=.o)
PRINTF_SRC_FULLNAME			= $(addprefix ./src/, $(PRINTF_SRC))
PRINTF_OBJ_FULLNAME			= $(addprefix ./obj/, $(PRINTF_SRC:.c=.o))
PRINTF_DPS_FULLNAME			= $(addprefix ./obj/, $(PRINTF_SRC:.c=.d))

PRINTF_SRC_BONUS 			= ft_printf_bonus.c ft_fmt_csper_bonus.c ft_fmt_diuoxXp_bonus.c ft_init_ag.c \
								ft_num_allocate_bonus.c ft_cs_allocate_bonus.c ft_printf_utils_bonus.c
PRINTF_OBJ_BONUS			= $(PRINTF_SRC_BONUS:.c=.o)
PRINTF_SRC_BONUS_FULLNAME	= $(addprefix ./bonus_src/, $(PRINTF_SRC_BONUS))
PRINTF_OBJ_BONUS_FULLNAME	= $(addprefix ./obj/, $(PRINTF_SRC_BONUS:.c=.o))
PRINTF_DPS_BONUS_FULLNAME	= $(addprefix ./obj/, $(PRINTF_SRC_BONUS:.c=.d))

ifdef PRINTF_BONUS
OBJS = $(PRINTF_OBJ_BONUS_FULLNAME)
DEPS = $(PRINTF_DPS_BONUS_FULLNAME)
else
OBJS = $(PRINTF_OBJ_FULLNAME)
DEPS = $(PRINTF_DPS_FULLNAME)
endif

VPATH = ./src:./bonus_src

all:make-objdir make-libft $(NAME)

$(NAME):$(LIBFT_NAME) $(OBJS)
	cp $(LIBFT_NAME) $(NAME)
	ar -rc $(NAME) $(OBJS)

.PHONY:make-objdir make-libft
make-objdir:
	if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi
make-libft:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o:%.c
	$(CC) $(CFLAGS) $(INCFLAG) $(DEPSFLAG) -o $@ -c $<

clean:
	rm -rf $(PRINTF_OBJ_FULLNAME)
	rm -rf $(PRINTF_DPS_FULLNAME)
	rm -rf $(PRINTF_OBJ_BONUS_FULLNAME)
	rm -rf $(PRINTF_DPS_BONUS_FULLNAME)
	rm -rf $(LIBFT_NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:clean
	rm -rf $(NAME)

bonus:
	make PRINTF_BONUS=1

re :fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
