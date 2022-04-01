NAME		=	time_test
SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)
DEPS		=	$(SRCS:.cpp=.d)
CC			=	clang++
RM			=	rm -f
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror
%.o			:	%.cpp
				$(CC) $(CFLAGS) -c $< -o $@ -MD

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

clean		:
				$(RM) $(OBJS) $(DEPS)

fclean		:	clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

-include $(DEPS)