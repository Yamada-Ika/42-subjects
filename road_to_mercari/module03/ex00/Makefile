NAME	:= omikuji
SRCS	:= main.go

all: $(NAME)

$(NAME): $(SRCS)
	go build -o $(NAME) $(SRCS)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

draw:
	@curl -I localhost:8080
	@curl localhost:8080

.PHONY: all clean fclean re test