CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

SRCS	= megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= megaphone

all:	$(NAME)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $<

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
