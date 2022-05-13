NAME		=	ft_containers

CPP			=	c++ -Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp
OBJ			=	$(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CPP) -c $< -o $@

$(NAME): $(OBJ) MAKEFILE
	@echo "\033[0;35mСоздаю исполняемый файл...\033[0;32m"
	@$(CPP) $(OBJ) -o $(NAME)

clean:
	@echo "\033[0;35mУдаляю объектные файлы...\033[0;31m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[0;35mУдаляю исполняемый файл...\033[0;31m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
