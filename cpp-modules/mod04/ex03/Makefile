CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors
INCLUDE		:= -I src

NAME	:= a.out
SRCS	:= AMateria.cpp \
Character.cpp \
Cure.cpp \
Ice.cpp \
MateriaSource.cpp \
main.cpp
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

run-pdftest: all
	export IYAMADA_REVIE_CPP04_EX03_PDFTEST=TRUE; ./a.out
run-clonetest: all
	export IYAMADA_REVIE_CPP04_EX03_CLONETEST=TRUE; ./a.out
run-copytest: all
	export IYAMADA_REVIE_CPP04_EX03_COPYTEST=TRUE; ./a.out
leak-pdftest: all
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	export IYAMADA_REVIE_CPP04_EX03_PDFTEST=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp
leak-clonetest: all
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	export IYAMADA_REVIE_CPP04_EX03_CLONETEST=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp
leak-copytest: all
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	export IYAMADA_REVIE_CPP04_EX03_COPYTEST=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp

debug-copytest:
	$(CC) -o debug $(SRCS) $(INCLUDE) -g -fsanitize=address
	-export IYAMADA_REVIE_CPP04_EX03_COPYTEST=TRUE; ./debug
	$(RM) debug

.PHONY: all clean fclean re run
