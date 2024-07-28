NAME = program

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinlcude

CPP = c++

SRC_DIR = src

OBJ_DIR = obj

SRCS = $(SRC_DIR)/Weapon.cpp \
		$(SRC_DIR)/HumanA.cpp \
		$(SRC_DIR)/HumanB.cpp \
		$(SRC_DIR)/main.cpp \

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re