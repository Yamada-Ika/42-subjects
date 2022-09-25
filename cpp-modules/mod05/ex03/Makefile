CC		:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS	:= -std=c++98 -pedantic-errors #-g -fsanitize=address
INCLUDE	:= -I src

NAME	:= a.out
SRCS	:= Bureaucrat.cpp             Intern.cpp                 RobotomyRequestForm.cpp    main.cpp\
Form.cpp                   PresidentialPardonForm.cpp ShrubberyCreationForm.cpp
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
	./a.out

leak: ## Check memory leak with leaks command
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	-c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp

.PHONY: help
help: ## Print Makefile rules
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-10s\033[0m %s\n", $$1, $$2}'

.PHONY: h
h: help ## Print Makefile rules (shorthand)

.PHONY: all clean fclean re test run
