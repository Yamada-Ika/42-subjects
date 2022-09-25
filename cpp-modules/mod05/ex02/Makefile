CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors
INCLUDE		:= -I src

NAME	:= a.out
SRCS	:= Bureaucrat.cpp             RobotomyRequestForm.cpp\
Form.cpp                   ShrubberyCreationForm.cpp\
PresidentialPardonForm.cpp main.cpp
OBJS	:= $(SRCS:%.cpp=%.o)
SRCS	:= $(addprefix src/, $(SRCS))
OBJS	:= $(addprefix obj/, $(OBJS))

.PHONY: all
all: $(NAME) ## Build

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CXXFLAGS) $(COPTS) $(INCLUDE) $(OBJS)

obj/%.o: src/%.cpp
	$(CC) $(CXXFLAGS) $(COPTS) $(INCLUDE) -o $@ -c $^

.PHONY: clean
clean: ## Remove object files
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean ## Remove object files and executable file
	$(RM) $(NAME)

.PHONY: re
re: fclean all ## Rebuild

.PHONY: run
run: all ## Run test
	./a.out

.PHONY: help
help: ## Print Makefile rules
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-10s\033[0m %s\n", $$1, $$2}'

.PHONY: h
h: help ## Print Makefile rules (shorthand)

