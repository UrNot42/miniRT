##########
# BASICS #
##########

NAME		:=	minirt

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

DBFLAGS		:=	-g -g3

LDLIBS		=	-lm -L./$(LIB_DIR)$(MLX_DIR) -lmlx -lXext -lX11 -I$(INCLUDE_DIR)

RM			:=	rm -rf

MV			:=	mv

ECHO		:=	/bin/echo -e

MAKE_SUB	:=	make --no-print-directory -s -C

QUIET		:=	 > /dev/null 2>&1

#######
# VAR #
#######

IS_DEBUG	:=	0

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

SRCL_ERR	=	$(addprefix $(ERR_DIR), $(SRC_ERROR))

SRCL_PARS	=	$(addprefix $(PARS_DIR), $(SRC_PARSING))

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

OBJ_DIR		:=	.build/

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
				@if [ $(IS_DEBUG) -eq 1 ]; then \
					$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(LDLIBS) -o $@; \
				else \
					$(CC) $(CFLAGS) -c $< $(LDLIBS) -o $@; \
				fi


$(LIBS):
				@for lib in $(LIBS); do \
					$(MAKE_SUB) $$(dirname $$lib) $(QUIET); \
				done

debug:			$(eval IS_DEBUG := 1) $(OBJS) $(LIBS) $(HEADERS)
				$(CC) -o $(NAME) $(OBJS) $(DBFLAGS) $(LDLIBS) $(MY_LIBS)
				@if [ ! -d $(NAME) ]; then \
					$(ECHO) "$(_IRED)$(_BOLD)Successfuly built $(_UNDER)$(NAME)$(_END)$(_IRED)$(_BOLD) with $(_ICYAN)db flags!$(_END)"; \
				fi

no-flags:		$(OBJS) $(LIBS) $(HEADERS) $(DEPS)
				@$(CC) -o $(NAME) $(OBJS) $(LDLIBS) $(MY_LIBS)
				@if [ ! -d $(NAME) ]; then \
					$(ECHO) "$(_YELLOW)$(_BOLD)Successfuly built $(_UNDER)$(NAME)$(_END)$(_YELLOW)$(_BOLD) with no flags ! $(_RED)/!\\ $(_END)"; \
				fi

$(NAME):		$(OBJS) $(LIBS) $(HEADERS) $(DEPS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS) $(MY_LIBS)
				@if [ ! -d $(NAME) ]; then \
					$(ECHO) "$(_BLUE)$(_BOLD)Successfuly built $(_UNDER)$(NAME)!$(_END)"; \
				fi

clean:
				@for lib in $(LIBS); do \
					$(MAKE_SUB) $$(dirname $$lib) clean $(QUIET); \
				done
				@$(RM) $(OBJ_DIR)
				@if [ ! -d $(OBJ_DIR) ]; then \
					$(ECHO) "$(_RED)$(_BOLD)Successfuly removed OBJECT files!$(_END)"; \
				fi

fclean:			clean
				@$(RM) $(NAME)
				@if [ ! -d $(OBJ_DIR) ]; then \
					$(ECHO) "$(_GREEN)$(_BOLD)Removed $(_UNDER)$(NAME)$(_END)"; \
				fi


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
				@$(ECHO) "$(_BLUE)                                           ▒▒░░░░░░░░░░░░                "
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
