CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic

NAME	:= Account
SRCS	:= tests.cpp Account.cpp
OBJS	:= $(SRCS:%.cpp=%.o)
SRCS	:= $(addprefix src/, $(SRCS))
OBJS	:= $(addprefix obj/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(COPTS) $(OBJS)

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(COPTS) -o $@ -c $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: SHELL:=/bin/bash
test:
	@diff <(./Account | awk '{$$1=""; print}') <(cat 19920104_091532.log | awk '{$$1=""; print}')

.PHONY: all clean fclean re
