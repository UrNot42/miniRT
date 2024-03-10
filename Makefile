##########
# BASICS #
##########

NAME		:=	minirt

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror -fenable-matrix

PRINT_HEAD	:=	 -H -fsyntax-only

DBFLAGS		:=	-g -g3

LDLIBS		=	-lm -L./$(LIB_DIR)$(MLX_DIR) -lmlx -lXext -lX11

RM			:=	rm -rf

MV			:=	mv

ECHO		:=	/bin/echo -e

MAKE_SUB	:=	make --no-print-directory -s -C

QUIET		:=	 > /dev/null 2>&1

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
				num_setters.c \

SRC_MATH	=	tuples_set.c \
				bool_tuples.c \
				float_operation.c \
				vector_operation.c \
				color_operation.c \
				$(addprefix $(MATRIX_DIR), $(SRC_MATRIX)) \

SRC_MATRIX	:=	matrix.c \
				matrix_set.c \
				matrix_bool.c \
				matrix_determinant.c \
				matrix_minor_and_cofactor.c \
				transform.c \

SRC_GRAPH	:=	canvas.c \
				image.c \
				window.c \
				pixel.c \
				printing.c \

SRC_TEST	:=	tuples.c \
				print_scenario.c \
				launch.c \
				vectors.c \
				colors.c \
				canvas.c \
				matrix.c \
				transform.c \
				firing_projectiles.c # TODO RM

############
# INCLUDED #
############

INCLUDE		=	-I$(INCLUDE_DIR)

HEADERS		=	$(addprefix $(INCLUDE_DIR), $(HEADER_LIST))

HEADER_LIST	:=	minirt.h \
				rt_error.h \
				rt_graphic.h \
				rt_math.h \
				rt_obj.h \
				rt_parsing.h \
				rt_test.h \

# HEADER_LIB	=	$(LIBS:.a=.h)

DEPS		=	$(INCLUDE_DIR) Makefile

###########
# SOURCES #
###########

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_ALL))

SRC_ALL		=	$(SRC_LIST) \
				$(SRCL_ERR) \
				$(SRCL_PARS) \
				$(SRCL_MATH) \
				$(SRCL_GRAPH) \
				$(SRCL_TEST) \

SRCL_ERR	=	$(addprefix $(ERR_DIR), $(SRC_ERROR))

SRCL_PARS	=	$(addprefix $(PARS_DIR), $(SRC_PARSING))

SRCL_TEST	=	$(addprefix $(TEST_DIR), $(SRC_TEST))

SRCL_MATH	=	$(addprefix $(MATH_DIR), $(SRC_MATH))

SRCL_GRAPH	=	$(addprefix $(GRAPH_DIR), $(SRC_GRAPH))

OBJS		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

###############
# DIRECTORIES #
###############

SRC_DIR		:=	src/

INCLUDE_DIR	:=	includes/

LIB_DIR		:=	lib/

LIBS_DIR	:=	$(dirname $(LIBS))

ERR_DIR		:=	errors/

PARS_DIR	:=	parsing/

TEST_DIR	:=	test/

MATH_DIR	:=	math/

MATRIX_DIR	:=	matrix/

GRAPH_DIR	:=	graphic/

OBJ_DIR		:=	build/

MLX_DIR		=	minilibx-linux/

#############
# LIBRARIES #
#############

LIBS		=	$(MY_LIBS) $(addprefix $(LIB_DIR), $(WRAPPED_LIB))

MY_LIBS		=	$(addprefix $(LIB_DIR), $(SRC_LIB))

SRC_LIB		:=	libft/libft.a \
				get_next_line/libgnl.a \
				ft_printf/libftprintf.a \

WRAPPED_LIB	=	$(MLX_DIR)libmlx.a

#########
# RULES #
#########

all:	$(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(INCLUDE) -o $@;

$(LIBS):
				@for lib in $(LIBS); do \
					$(ECHO) "$(_CYAN)..making $(_UNDER)$$lib$(_END)"; \
					$(MAKE_SUB) $$(dirname $$lib) $(QUIET); \
					if [ -f "$$lib" ]; then \
						$(ECHO) "$(_CYAN)$(_BOLD)Built $(_UNDER)$$lib$(_END)"; \
					else \
						$(ECHO) "$(_RED)$(_BOLD)Failed to build $(_UNDER)$$lib$(_END)"; \
					fi \
				done

debug:			$(OBJS) $(LIBS) $(HEADERS)
				$(CC) -o $(NAME) $(OBJS) $(DBFLAGS) $(LDLIBS) $(INCLUDE) $(MY_LIBS)
				@if [ -f $(NAME) ]; then \
					$(ECHO) "$(_IRED)$(_BOLD)Successfuly built $(_UNDER)$(NAME)$(_END)$(_IRED)$(_BOLD) with $(_ICYAN)db flags!$(_END)"; \
				else \
					$(ECHO) "$(_IRED)$(_BOLD)Error while building $(_IBLUE)$(NAME)$(_END)"; \
				fi

no-flags:		$(OBJS) $(LIBS) $(HEADERS) $(DEPS)
				@$(CC) -o $(NAME) $(OBJS) $(LDLIBS) $(INCLUDE) $(MY_LIBS)
				@if [ -f $(NAME) ]; then \
					$(ECHO) "$(_YELLOW)$(_BOLD)Successfuly built $(_UNDER)$(NAME)$(_END)$(_YELLOW)$(_BOLD) with no flags ! $(_RED)/!\\ $(_END)"; \
				else \
					$(ECHO) "$(_RED)$(_BOLD)Error while building $(_IRED)$(NAME)$(_END)"; \
				fi

$(NAME):		$(OBJS) $(LIBS) $(HEADERS) $(DEPS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS) $(INCLUDE) $(MY_LIBS)
				@if [ -f $(NAME) ]; then \
					$(ECHO) "$(_BLUE)$(_BOLD)Successfuly built $(_UNDER)$(NAME)!$(_END)"; \
				else \
					$(ECHO) "$(_PURPLE)$(_BOLD)Error while building $(_UNDER)$(NAME)!$(_END)"; \
				fi

clean:
				@$(RM) $(OBJ_DIR)
				@if [ ! -d $(OBJ_DIR) ]; then \
					$(ECHO) "$(_GREEN)$(_BOLD)Successfuly removed OBJECT files!$(_END)"; \
				else \
					$(ECHO) "$(_RED)$(_BOLD)Failed to remove OBJECT files!$(_END)"; \
				fi
				@for lib in $(LIBS); do \
					$(ECHO) "$(_CYAN)..cleaning $(_UNDER)$$lib$(_END)"; \
					$(MAKE_SUB) $$(dirname $$lib) clean $(QUIET); \
					$(MAKE_SUB) $$(dirname $$lib) fclean $(QUIET); \
					if [ -f "$$lib" ]; then \
						$(ECHO) "$(_RED)$(_BOLD) Failed to clean $(_UNDER)$$lib$(_END)"; \
					else \
						$(ECHO) "$(_CYAN)$(_BOLD) Cleaned $(_UNDER)$$lib$(_END)"; \
					fi \
				done

fclean:			clean
				@$(RM) $(NAME)
				@if [ ! -d $(OBJ_DIR) ]; then \
					$(ECHO) "$(_IBLUE)$(_BOLD)Removed $(_UNDER)$(NAME)$(_END)"; \
				else \
					$(ECHO) "$(_IPURPLE)$(_BOLD)Failed to remove $(_UNDER)$(NAME)$(_END)"; \
				fi
				@$(ECHO) "$(_GREEN)$(_BOLD)====================$(_END)"
				@$(ECHO) "$(_GREEN)$(_BOLD)Full Clean complete!$(_END)"
				@$(ECHO) "$(_GREEN)$(_BOLD)====================$(_END)"; \

re:				fclean all

bonus:			all

.PHONY:			all clean fclean re debug bonus no-flags

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

banner:
				@$(ECHO) "$(_BLUE)                                         ▒▒░░░░░░░░░░░░                  "
				@$(ECHO) "$(_YELLOW)            _       _______ _____    $(_BLUE)▒▒▒▒▒▒▒░░░░░░░░░░░░     ░░          "
				@$(ECHO) "$(_YELLOW)           (_)     (_) ___ \\_   _| $(_BLUE)▒▒▒▒▒▒▒▒░░░░░░░░░░░         ░░        "
				@$(ECHO) "$(_YELLOW)  _ __ ___  _ _ __  _| |_/ / | |$(_BLUE)░▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░            ░░      "
				@$(ECHO) "$(_YELLOW) | '_ \` _ \\| | '_ \\| |    /  |$(_BLUE)▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░            ░░░░    "
				@$(ECHO) "$(_YELLOW) | | | | | | | | | | | |\\ \\  $(_BLUE)▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░        ░░░░░░    "
				@$(ECHO) "$(_YELLOW) |_| |_| |_|_|_| |_|_\\_| \\_$(_BLUE)▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░    ░░░░░░░░░░  "
				@$(ECHO) "$(_BLUE)                           ▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░  "
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒"
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░▒▒"
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░▒▒▒▒"
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒▒▒"
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒"
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒"
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒"
				@$(ECHO) "$(_BLUE)                         ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  "
				@$(ECHO) "$(_BLUE)                           ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓  "
				@$(ECHO) "$(_BLUE)                           ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒  "
				@$(ECHO) "$(_BLUE)                             ▓▓██▓▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    "
				@$(ECHO) "$(_BLUE)                               ▓▓▓▓████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      "
				@$(ECHO) "$(_BLUE)                                 ████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      "
				@$(ECHO) "$(_BLUE)                                   ████████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓        "
				@$(ECHO) "$(_BLUE)                     ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██████████████▓▓▓▓▓▓▓▓▓▓▓▓          "
				@$(ECHO) "$(_BLUE)           ░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██████████████████▒▒▒▒▒▒▒▒      "
				@$(ECHO) "$(_BLUE)                 ░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒            "
