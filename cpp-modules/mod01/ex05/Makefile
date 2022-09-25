CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors
INCLUDE		:= -I src

NAME	:= Harl
SRCS	:= main.cpp Harl.cpp
OBJS	:= $(SRCS:%.cpp=%.o)
SRCS	:= $(addprefix src/, $(SRCS))
OBJS	:= $(addprefix obj/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CXXFLAGS) $(COPTS) $(INCLUDE) $(OBJS)

obj/%.o: src/%.cpp
	$(CC) $(CXXFLAGS) $(COPTS) $(INCLUDE) -o $@ -c $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: SHELL := /bin/bash
test: all
	@diff <(./Harl) <(echo -ne "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\nThis is unacceptable! I want to speak to the manager now.\nProbably complaining about insignificant problems\n")

.PHONY: all clean fclean re test
