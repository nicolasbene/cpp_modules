CC			= c++
CPPFLAGS	= -Wall -Wextra -std=c++98
CPPFLAGS	+= -Werror
CPPFLAGS	+= -g
CPPFLAGS	+= -MMD -MP
IFLAGS		= 
RM			= rm -rf
OBJ_DIR		= bin

SRCS	= main.cpp \
		  Bureaucrat.cpp \
		  AForm.cpp \
		  ShrubberyCreationForm.cpp \
		  RobotomyRequestForm.cpp \
		  PresidentialPardonForm.cpp \

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS	= $(OBJS:.o=.d)

NAME	= bureaucrat

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
