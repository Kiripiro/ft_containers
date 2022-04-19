# Colors
GREY = \033[4;34m
RED = \033[1;31m
GREEN = \033[3;32m
YELLOW = \033[2;49;33m
BLUE = \033[4;34m
BLUEE = \033[3;34m
PURPLE = \033[3;35m
CYAN = \033[3;36m
RESET = \033[0m
ICONOK = \033[1;32m
ICONKO = \033[1;31m
CO_DELET = \033[3;31m
CO_A_OUT = \033[96m
WHITE = \033[1;49;97m
ERASE = \033[2K\r

FT_NAME			=	ft_containers
STD_NAME		=	std_containers

INCS_DIR		=	incs

-include			includes.mk
-include			sources.mk
-include			tests_sources.mk

INCS			=	$(INCLUDES)
OBJS			=	$(SOURCES:.cpp=.o)
STD_OBJS		=	$(TESTS_SOURCES:.cpp=.o)

CC				=	@clang++
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -g

all: $(FT_NAME)

$(FT_NAME): $(INCS) $(OBJS)
	@printf "$(ERASE)$(BLUE)$(FT_NAME):$(GREEN) Compiling FT project.\n$(RESET)"
	@$(CC) $(FLAGS) -I $(INCS_DIR) -o $(FT_NAME) $(OBJS)
	@mkdir .objs && mv $(OBJS) .objs
	@printf "$(ERASE)$(BLUE)$(FT_NAME):$(GREEN) Project compiled.\n$(RESET)"

$(STD_NAME): $(INCS) $(STD_OBJS)
	@printf "$(ERASE)$(BLUE)$(STD_NAME):$(GREEN) Compiling STD project.\n$(RESET)"
	@$(CC) $(FLAGS) -I $(INCS_DIR) -o $(STD_NAME) $(STD_OBJS)
	@mv $(STD_OBJS) .objs
	@printf "$(ERASE)$(BLUE)$(STD_NAME):$(GREEN) Project compiled.\n$(RESET)"

%.o: %.cpp $(INCS)
	@printf "$(ERASE)$(BLUE)$(FT_NAME): Compiling $(RESET)$(GREEN)$<$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@printf "$(BLUE)$(FT_NAME):$(GREEN) Removing objects.\n$(RESET)"
	@rm -rf .objs

fclean: clean
	@printf "$(BLUE)$(FT_NAME):$(GREEN) Cleaning project.\n$(RESET)"
	@rm -rf $(FT_NAME)

re:	gmk fclean all

gmk:
	@printf "$(BLUE)$(FT_NAME):$(GREEN) Generating Makefile includes.\n$(RESET)"
	@find tests/ft/*/*.cpp | sed 's/^/SOURCES += /' > sources.mk && echo "SOURCES += tests/ft/main.cpp" >> sources.mk
	@find incs/*/*.hpp | sed 's/^/INCLUDES += /' > includes.mk

gmk_diff:
	@printf "$(BLUE)$(FT_NAME):$(GREEN) Generating Makefile includes.\n$(RESET)"
	@find tests/ft/*/*.cpp | sed 's/^/SOURCES += /' > sources.mk && echo "SOURCES += tests/ft/main.cpp" >> sources.mk
	@find tests/std/*/*.cpp | sed 's/^/TESTS_SOURCES += /' > tests_sources.mk && echo "TESTS_SOURCES += tests/std/std_main.cpp" >> tests_sources.mk
	@find incs/*/*.hpp | sed 's/^/INCLUDES += /' > includes.mk

diff: $(FT_NAME) $(STD_NAME)

fclean_diff: fclean
	@printf "$(BLUE)$(STD_NAME): $(GREEN)Cleaning project.\n$(RESET)"
	@rm -rf $(STD_NAME)

.PHONY: all clean fclean re gmk diff
