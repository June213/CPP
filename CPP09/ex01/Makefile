NAME = RPN

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinlcude

CPP = c++

SRC_DIR = src

OBJ_DIR = obj

SRCS = 	$(SRC_DIR)/RPN.cpp \
		$(SRC_DIR)/main.cpp


OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

YELLOW = \033[33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Executable $(YELLOW)$(NAME)$(RESET) created "

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Removing $(YELLOW)$(OBJ_DIR)$(RESET) directory"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removing $(YELLOW)$(NAME)$(RESET) executable"

re: fclean all

.PHONY: all clean fclean re