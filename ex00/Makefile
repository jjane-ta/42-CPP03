# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 12:46:18 by jjane-ta          #+#    #+#              #
#    Updated: 2023/02/07 16:59:23 by jjane-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_ClapTrap

SRC = ClapTrap.cpp main.cpp
OBJ = $(addprefix .,$(addsuffix .o,$(basename $(SRC))))
DEP = $(addprefix .,$(addsuffix .d,$(basename $(SRC))))

CXX = c++ -std=c++98 -pedantic
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP

.%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

-include $(DEP)
$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean : 
	$(RM) $(OBJ) $(DEP)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY : re clean fclean

