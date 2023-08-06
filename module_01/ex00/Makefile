CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
CPPFLAGS	+= -g
CPPFLAGS	+= -MMD
RM			= rm -rf
OBJ_DIR		= bin

SRCS	= main.cpp \
		  Zombie.cpp \
		  newZombie.cpp \
		  randomChump.cpp \

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(OBJS:.o=.d)

NAME	= zombie

all:	$(NAME)

$(OBJ_DIR)/%.o:	%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
