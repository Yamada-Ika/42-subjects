CC			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror
COPTS		:= -std=c++98 -pedantic-errors
INCLUDE		:= -I src

NAME	:= sed
SRCS	:= main.cpp Sed.cpp
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

run: SHELL := /bin/bash
run: all
	@echo 'aaaahogebbbbhogecccchoge' > test.file
	./sed test.file 'hoge' 'fuga'
	@diff test.file.replace <(cat test.file | sed -e 's/hoge/fuga/g')
	@echo 'helloaaaworldbbbb' > test.file
	./sed test.file 'hello' 'world'
	@diff test.file.replace <(cat test.file | sed -e 's/hello/world/g')
	@echo 'abcdefg' > test.file
	./sed test.file 'a' 'b'
	@diff test.file.replace <(cat test.file | sed -e 's/a/b/g')
	@echo 'aaaaabbbbbbbcccccddddd' > test.file
	./sed test.file 'aaaa' ''
	@diff test.file.replace <(cat test.file | sed -e 's/aaaa//g')
	@echo '' > test.file
	./sed test.file 'aaaa' ''
	@diff test.file.replace <(cat test.file | sed -e 's/aaaa//g')
	@echo -ne "hoge\n\nfuga\nhello\n" > test.file
	./sed test.file "\n" "a"
	@diff test.file.replace <(cat test.file | sed -e 's/\n/a/g')
	@rm -rf test.file
	@rm -rf test.file.replace

error: all
	@echo -n "" > test.file
	-./sed test.file "" ""
	@touch noright.file
	@chmod 000 noright.file
	-./sed noright.file hoge fuga
	@mkdir -p dir
	-./sed dir hoge fuga
	-./sed nosuchfile hoge fuga
	-./sed
	-./sed dir
	-./sed dir 'a'
	@rm -rf noright.file
	@rm -rf test.file
	@rm -rf dir

.PHONY: all clean fclean re run error
