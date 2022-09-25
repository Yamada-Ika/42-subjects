NAME := inception

.PHONY: $(NAME)
$(NAME): all

.PHONY: all
all: ## Up docker container with compose
	docker-compose -f srcs/docker-compose.yml up

.PHONY: clean
clean: ## Down docker container with compose
	docker-compose -f srcs/docker-compose.yml down

.PHONY: fclean
fclean: clean ## Restore your environment before review

.PHONY: re
re: fclean all ## Rebuild docker container

.PHONY: init
init: clean-docker ## Initialize before review
	bash srcs/requirements/tools/init.sh

.PHONY: cleanup
cleanup: clean-docker ## Clean up after review
	bash srcs/requirements/tools/cleanup.sh

.PHONY: build
build:
	docker-compose -f srcs/docker-compose.yml build

.PHONY: ncbuild
ncbuild:
	docker-compose -f srcs/docker-compose.yml build --no-cache

.PHONY: check
check: ## Run check script along with check list
	./check.sh

.PHONY: clean-docker
clean-docker: ## Clean docker environment on your machine
	-docker stop $$(docker ps -qa)
	-docker rm $$(docker ps -aq)
	-docker rmi -f $$(docker images -qa)
	-docker volume rm $$(docker volume ls -q)
	-docker network rm $$(docker network ls -q) 2> /dev/null

.PHONY: help
help: ## Display this help screen
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' Makefile | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: h
h: help ## shorthand 'help' command
