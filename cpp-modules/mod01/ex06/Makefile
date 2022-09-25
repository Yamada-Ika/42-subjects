CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors
INCLUDE		:= -I src

NAME	:= harlFilter
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

run: all
	@echo "\033[036m-------- DEBUG --------\033[0m"
	./harlFilter "DEBUG"
	@echo "\033[036m-------- INFO --------\033[0m"
	./harlFilter "INFO"
	@echo "\033[036m-------- WARNING --------\033[0m"
	./harlFilter "WARNING"
	@echo "\033[036m-------- ERROR --------\033[0m"
	./harlFilter "ERROR"
	@echo "\033[036m-------- NOSUCHLEVEL --------\033[0m"
	./harlFilter "NOSUCHLEVEL"

.PHONY: all clean fclean re run
