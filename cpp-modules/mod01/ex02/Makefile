CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors

NAME	:= a.out
SRCS	:= main.cpp
OBJS	:= $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CXXFLAGS) $(COPTS) $(OBJS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(COPTS) -o $@ -c $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./a.out

.PHONY: all clean fclean re run
