# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:09:50 by pllucian          #+#    #+#              #
#    Updated: 2022/02/20 17:53:04 by pllucian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =	vector.hpp \
		map.hpp \
		stack.hpp \
		set.hpp \
		tree.hpp \
		iterator.hpp \
		iterator_base_types.hpp \
		type_traits.hpp \
		utility.hpp \
		algorithm.hpp \
		function.hpp

TESTS =	test_std.cpp \
		test_ft.cpp \
		test_vector.cpp \
		test_map.cpp \
		test_stack.cpp \
		test_set.cpp \

INCL = $(addprefix includes/, $(FILES))

OBJS = $(addprefix objs/, $(TESTS:.cpp=.o))

DEPS = $(wildcard objs/*.d)

NAMES = std ft vector map stack set

CXX = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

objs/%.o:	tests/%.cpp
			@ [ -d objs ] || mkdir -p objs
			$(CXX) $(CFLAGS) -MMD -c $< -o $@ -I./includes

all:		$(NAMES)

std:		objs/*std.o
			$(CXX) -o $@ objs/*std.o

ft:			objs/*ft.o
			$(CXX) -o $@ objs/*ft.o

vector:		objs/*vector.o
			$(CXX) -o $@ objs/*vector.o

map:		objs/*map.o
			$(CXX) -o $@ objs/*map.o

stack:		objs/*stack.o
			$(CXX) -o $@ objs/*stack.o

set:		objs/*set.o
			$(CXX) -o $@ objs/*set.o

clean:
			$(RM)r $(OBJS) $(DEPS) objs

fclean:		clean
			$(RM) $(NAMES)

re:			fclean all

.PHONY:		all clean fclean re

include		$(DEPS)
