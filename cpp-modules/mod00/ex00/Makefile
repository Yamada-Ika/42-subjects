CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors

NAME	:= megaphone
SRCS	:= megaphone.cpp
OBJS	:= megaphone.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(COPTS) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: SHELL:=/bin/bash
test:
	@diff <(./megaphone "shhhhh... I think the students are asleep...") <(echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...")
	@diff <(./megaphone Damnit " ! " "Sorry students, I thought this thing was off.") <(echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.")
	@diff <(./megaphone) <(echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *")

.PHONY: all clean fclean re
