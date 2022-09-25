CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors
INCLUDE		:= -I src

NAME	:= a.out
SRCS	:= \
Animal.cpp      Dog.cpp         WrongCat.cpp\
Cat.cpp         WrongAnimal.cpp main.cpp
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
	export IYAMADA_CPP04_EX00_NORMAL=TRUE; ./a.out

wrong: all
	export IYAMADA_CPP04_EX00_WRONG=TRUE; ./a.out; 

leak-normal:
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	-export IYAMADA_CPP04_EX00_NORMAL=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp

leak-wrong:
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	-export IYAMADA_CPP04_EX00_WRONG=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp

.PHONY: all clean fclean re run wrong leak-normal
