##########
# BASICS #
##########

NAME		:=	minirt

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

LDLIBS		=	-lm -L./obj -lmlx -lXext -lX11 -I$(INCLUDE_DIR)

RM			:=	rm -rf

MV			:=	mv

ECHO		:=	/bin/echo -e

MAKE_SUB	:=	make --no-print-directory -s -C

#########
# FILES #
#########

SRC_LIST	:=	main.c \

SRC_ERROR	:=	error.c \
				error_display.c

SRC_PARSING	:=	file_management.c \
				scene_fill.c \
				scene_management.c \
				size.c \
				parsing.c \
				obj_print.c \
				obj_setters.c \
				num_setters.c

SRC_GNL		:=	get_next_line.c \
				get_next_line_utils.c

############
# INCLUDED #
############

HEADERS		=	$(addprefix $(INCLUDE_DIR), $(HEADER_LIST))

HEADER_LIST	:=	minirt.h

DEPS		=	$(INCLUDE_DIR) Makefile

###########
# SOURCES #
###########

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_ALL))

SRC_ALL		=	$(SRC_LIST) \
				$(SRCL_ERR) \
				$(SRCL_PARS) \
				$(SRCL_GNL) \

SRCL_ERR	=	$(addprefix $(ERR_DIR), $(SRC_ERROR))

SRCL_PARS	=	$(addprefix $(PARS_DIR), $(SRC_PARSING))

SRCL_GNL	=	$(addprefix $(GNL_DIR), $(SRC_GNL))

OBJS		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

###############
# DIRECTORIES #
###############

SRC_DIR		:=	src/

INCLUDE_DIR	:=	includes/

LIB_DIR		:=	lib/

ERR_DIR		:=	errors/

PARS_DIR	:=	parsing/

GNL_DIR		:=	get_next_line/

OBJ_DIR		:=	obj/

#############
# LIBRARIES #
#############

LIBS		=	$(addprefix $(LIB_DIR), $(SRC_LIB))

SRC_LIB		:=	libft/ \
				ft_printf/ \
				minilibx-linux/ \

#########
# RULES #
#########

all:	$(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -g -c $< $(LDLIBS) -o $@

lib:			$(OBJ_DIR) $(LIBS)
				@for lib in $(LIBS); do \
					$(MAKE_SUB) $$lib; \
				done
				$(MV) $(LIB_DIR)minilibx-linux/libmlx.a $(OBJ_DIR)
				$(MV) $(LIB_DIR)libft/libft.a $(OBJ_DIR)
				$(MV) $(LIB_DIR)ft_printf/libftprintf.a $(OBJ_DIR)

debug:			$(OBJS) lib $(HEADERS)
				$(CC) -o $(NAME) $(OBJS) -g3 -g $(LDLIBS) $(OBJ_DIR)libft.a $(OBJ_DIR)libftprintf.a

$(NAME):		$(OBJS) lib $(HEADERS) $(DEPS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS) $(OBJ_DIR)libft.a $(OBJ_DIR)libftprintf.a

clean:
				@for lib in $(LIBS); do \
					$(MAKE_SUB) $$lib clean; \
				done
				@$(RM) $(OBJ_DIR)
				@if [ ! -d $(OBJ_DIR) ]; then \
					$(ECHO) "$(_RED)$(_BOLD)Successfuly removed OBJECT files!$(_END)$(_WHITE)"; \
				fi

fclean:			clean
				@$(RM) $(NAME)
				@if [ ! -d $(OBJ_DIR) ]; then \
					$(ECHO) "$(_GREEN)$(_BOLD)Removed $(_UNDER)$(NAME)$(_END)$(_WHITE)"; \
				fi


re:				fclean all

bonus:			all

.PHONY:			all clean fclean re debug bonus

################################
#            COLORS            #
################################

_GREY			=	\x1b[30m
_RED			=	\x1b[31m
_GREEN			=	\x1b[32m
_YELLOW			=	\x1b[33m
_BLUE			=	\x1b[34m
_PURPLE			=	\x1b[35m
_CYAN			=	\x1b[36m
_WHITE			=	\x1b[37m

# ANSI/VT100 COLOR CODES

_END			=	\x1b[0m
_BOLD			=	\x1b[1m
_UNDER			=	\x1b[4m
_REV			=	\x1b[7m

# BACKGROUND

_IGREY			=	\x1b[40m
_IRED			=	\x1b[41m
_IGREEN			=	\x1b[42m
_IYELLOW		=	\x1b[43m
_IBLUE			=	\x1b[44m
_IPURPLE		=	\x1b[45m
_ICYAN			=	\x1b[46m
_IWHITE			=	\x1b[47m
