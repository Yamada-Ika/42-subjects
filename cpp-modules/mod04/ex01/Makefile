CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors
INCLUDE		:= -I src

NAME	:= a.out
SRCS	:= \
Animal.cpp Cat.cpp    main.cpp\
Brain.cpp  Dog.cpp
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

run-normal: all
	export IYAMADA_CPP04_EX01_NORMAL=TRUE; ./a.out
run-normal2: all
	export IYAMADA_CPP04_EX01_NORMAL2=TRUE; ./a.out
run-copy: all
	export IYAMADA_CPP04_EX01_COPY=TRUE; ./a.out

leak-normal:
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	-export IYAMADA_CPP04_EX01_NORMAL=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp
leak-normal2:
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	-export IYAMADA_CPP04_EX01_NORMAL2=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp
leak-copy:
	@echo '#include <stdio.h>\n#include <unistd.h>\n#include <stdlib.h>\n#include <strings.h>\n__attribute__((destructor))\nvoid	destructor(void){char buf[50]; bzero(buf, 50); sprintf(buf, "leaks %d", getpid()); system(buf);}' > src/leak.cpp
	-export IYAMADA_CPP04_EX01_COPY=TRUE; c++ -o leak src/*.cpp && ./leak
	rm -rf ./leak src/leak.cpp

.PHONY: all clean fclean re run run-normal run-normal2 run-copy leak-normal leak-normal2 leak-copy
