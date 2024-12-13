#			-->|   Files to Compile   |<--
FILES		=		aux_itoas aux_types aux_checks aux_builds aux_utils ft_printf

#			-->|   Settings   |<--
PROG		=	0
EXT			=	1

#			-->|   Titles && Messages   |<--
HEAD		=		"42 Printf"
NAME		=		libftprintf.a
DIRS		=		libft

T_CREATING	=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD) at $(NAME) $(GRAY)...\n"
T_BUILDING	=		@echo "\n	$(GRAY)... $(BYELLOW)Building $@ $(GRAY)... \n"
T_COMPILING	=		@echo "	$(GRAY)... $(YELLOW)Compiling $< $(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) - main.c $(BLUE)at $(WHITE)exe $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	...$(BGREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#			-->|   Colors   |<--
GRAY		=		\033[0;30m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
WHITE		=		\033[0;37m
DEF			=		\033[0;39m

BGREEN		=		\033[1;32m
BYELLOW		=		\033[1;33m
BBLUE		=		\033[1;34m
BMAGENTA	=		\033[1;35m
BCYAN		=		\033[1;36m

#			-->|   Print Messsages   |<--


#			-->|   Conditional Command Definitions   |<--
START		=		1
ifeq ($(PROG),1)
INC_DIR		=		includes/
SRC_DIR		=		src/
else
INC_DIR		=		./
SRC_DIR		=		./
endif
OBJ_DIR		=		obj/

FLAGS		=		-Wall -Wextra -Werror
M			=		@make --no-print-directory

COMPILE		=		@cc $(FLAGS) -I $(INC_DIR) -c $< -o $@
EXE			=		@cc -I $(INC_DIR) -o exe main.c $(NAME) && ./exe && rm -f exe
RMV			=		@rm -rf $(OBJ_DIR)
AR			=		@ar -rcs $@ $(OBJ)

SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

ifeq ($(EXT), 1)
LIBS		=		$(addprefix $(DIRS)/, $(addsuffix .a, $(DIRS))) 
AR_EXT		=		$(M) -C $(DIRS) all && cp $(LIBS) $(NAME)
M_C			=		$(M) -C $(DIRS) clean
M_F			=		$(M) -C $(DIRS) fclean
else
AR_EXT		=
M_C			=
M_F			=
endif

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME)
	$(T_COMPILED)

bonus: re

clean:
	$(M_C)
	$(RMV)
	$(T_REMOVE_O)


fclean:
	$(M_F)
	$(RMV) $(NAME)
	$(T_REMOVE_A)

re: fclean all

exe: re
	$(T_EXECUTING)
	$(EXE)
	$(T_EXECUTED)

#			-->|   File Dependencies   |<--
$(START):
	$(T_CREATING)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(NAME): $(OBJ)
	$(T_BUILDING)
	$(AR_EXT)
	$(AR)
