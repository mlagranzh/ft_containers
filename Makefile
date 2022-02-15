NAME		=	ft_container
HEADER		=	

CPP			=	c++ -std=c++98
SRCS		=	main.cpp
OBJ			=	$(SRCS:.cpp=.o)

all: $(NAME)

.cpp.o :
	${CPP} -c $< -o ${<:.cpp=.o}

$(NAME): $(OBJ) $(HEADER) MAKEFILE
	@echo "\033[0;35mСоздаю исполняемый файл...\033[0;32m"
	@$(CPP) -o $(NAME) $(OBJ)

clean:
	@echo "\033[0;35mУдаляю объектные файлы...\033[0;31m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[0;35mУдаляю исполняемый файл...\033[0;31m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
