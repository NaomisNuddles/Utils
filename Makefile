#			-->|   Titles && Messages   |<--
HEAD		=		"42 Build"
NAME		=		ft_build.a

L_HEAD		=		"42 Library"
L_NAME		=		libft.a
L_DIR		=		libft/

P_HEAD		=		"42 Printf"
P_NAME		=		libftprintf.a
P_DIR		=		ft_printf/

G_HEAD		=		"Get Next Line"
G_NAME		=		gnl.a
G_DIR		=		gnl/

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

#			-->|   Conditional Command Definitions   |<--
START		=		1
INC_DIR		=		includes/
OBJ_DIR		=		obj/

FLAGS		=		-Wall -Wextra -Werror
M			=		@make --no-print-directory

COMPILE		=		@cc $(FLAGS) -I $(INC_DIR) -c $< -o $@
EXE			=		@cc -I $(INC_DIR) -o exe main.c $(NAME) && ./exe && rm -f exe
RMV			=		@rm -rf $(OBJ_DIR)
AR			=		@ar -rcs $@ $<

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME)
	$(T_COMPILED)

lib: $(L_NAME)
	$(T_COMPILED)

print: $(L_NAME) $(P_NAME)
	@cp $(L_NAME) $(P_NAME)
	@rm -f $(L_NAME)
	$(T_COMPILED)

gnl: $(L_NAME) $(G_NAME)
	@cp $(L_NAME) $(G_NAME)
	@rm -f $(L_NAME)
	$(T_COMPILED)

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
$(START): $(HEAD)
	$(T_CREATING)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(L_NAME):
	$(OBJ_DIR)*.o: $(L_DIR)*.c | $(OBJ_DIR)
		$(T_COMPILING)
		$(COMPILE)
	$(T_BUILDING)
	$(AR_EXT)

$(P_NAME):
	$(OBJ_DIR)*.o: $(P_DIR)*.c | $(OBJ_DIR)
		$(T_COMPILING)
		$(COMPILE)
	$(T_BUILDING)
	$(AR_EXT)

$(G_NAME):
	$(OBJ_DIR)%.o: $(G_DIR)%.c | $(OBJ_DIR)
		$(T_COMPILING)
		$(COMPILE)
	$(T_BUILDING)
	$(AR_EXT)

$(NAME): $(L_NAME) $(P_NAME) $(G_NAME)
	$(T_BUILDING)
	@cp $(L_NAME) $(P_NAME) $(G_NAME) $(NAME)
	@rm -f $(L_NAME) $(P_NAME) $(G_NAME)
