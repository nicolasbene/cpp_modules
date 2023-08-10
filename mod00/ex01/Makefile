CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
CPPFLAGS	+= -MMD
RM			= rm -rf
OBJ_DIR		= bin

SRCS	= main.cpp \
		  PhoneBook.cpp \
		  Contact.cpp \

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

NAME	= phonebook

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
