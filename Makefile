# BASICS

NAME		=	minirt

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

LDLIBS		=	-lm -L./obj -lmlx -lXext -lX11 -I$(INCLUDE_DIR)

RM			=	rm -rf

MAKE_SUB	=	make -C

# FILES

SRC_LIST	=	main.c \

SRC_ERROR	=	error.c \
				error_display.c

SRC_PARSING	=	file_management.c \
				scene_fill.c \
				scene_management.c \
				size.c \
				parsing.c \
				obj_print.c \
				obj_setters.c \
				num_setters.c

SRC_GNL		=	get_next_line.c \
				get_next_line_utils.c

# INCLUDED

HEADERS		=	$(addprefix, $(INCLUDE_DIR), $(HEADER_LIST))

HEADER_LIST	=	minirt.h

DEPS		=	libft/ Makefile

# SOURCES

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_ALL))

SRC_ALL		=	$(SRC_LIST) \
				$(SRCL_ERR) \
				$(SRCL_PARS) \
				$(SRCL_GNL) \

SRCL_ERR	=	$(addprefix $(ERR_DIR), $(SRC_ERROR))

SRCL_PARS	=	$(addprefix $(PARS_DIR), $(SRC_PARSING))

SRCL_GNL	=	$(addprefix $(GNL_DIR), $(SRC_GNL))

OBJS		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

# DIRECTORIES

SRC_DIR		=	src/

INCLUDE_DIR	=	includes/

ERR_DIR		=	errors/

PARS_DIR	=	parsing/

GNL_DIR		=	get_next_line/

OBJ_DIR		=	obj/

all:	$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
				mkdir -p $(OBJ_DIR)
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -g -c $< $(LDLIBS) -o $@

debug:			$(OBJS) $(HEADERS)
				$(MAKE_SUB) libft/
				$(MAKE_SUB) ft_printf/
				$(MAKE_SUB) minilibx-linux/
				mv minilibx-linux/libmlx.a obj/
				mv libft/libft.a obj/
				mv ft_printf/libftprintf.a obj/
				$(CC) -o $(NAME) $(OBJS) -g3 -g $(LDLIBS) obj/libft.a obj/libftprintf.a

$(NAME):		$(OBJS) $(HEADERS) $(DEPS)
				$(MAKE_SUB) libft/
				$(MAKE_SUB) ft_printf/
				$(MAKE_SUB) minilibx-linux/
				mv minilibx-linux/libmlx.a obj/
				mv libft/libft.a obj/
				mv ft_printf/libftprintf.a obj/
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS) obj/libft.a obj/libftprintf.a

clean:
				$(RM) $(OBJ_DIR)
				$(MAKE_SUB) libft/ clean
				$(MAKE_SUB) ft_printf/ clean
				$(MAKE_SUB) minilibx-linux/ clean

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			all

.PHONY:			all clean fclean re debug bonus
