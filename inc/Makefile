VOLUME_DIR:=/home/sounchoi/data
VOLUME_DB:=$(VOLUME_DIR)/db
VOLUME_WEB:=$(VOLUME_DIR)/web

all : 
	mkdir -p $(VOLUME_DB) $(VOLUME_WEB)
	docker-compose -f srcs/docker-compose.yml up -d

ft_mariadb :
	mkdir -p $(VOLUME_DB) $(VOLUME_WEB)
	docker-compose -f srcs/docker-compose.yml up -d ft_mariadb

# nginx:
# 	docker-compose -f srcs/docker-compose.yml up -d nginx

# wordpress:
# 	docker-compose -f srcs/docker-compose.yml up -d wordpress

clean:
	docker stop $(shell docker ps -aq) || true
	docker rm $(shell docker ps -aq)|| true

fclean: 
	make clean || true
	docker image rm $(shell docker images -q) || true
	docker system prune --all --volumes --force
	docker volume prune
	docker volume rm database web 2> /dev/null
	sudo rm -rf $(VOLUME_DIR)

# mariadb_fclean:
# 	docker stop mariadb
# 	docker rm mariadb
# 	docker image rm mariadb
# 	sudo rm -rf $(VOLUME_DB)

# nginx_fclean:
# 	docker stop nginx
# 	docker rm nginx
# 	docker image rm nginx

# wordpress_fclean:
# 	docker stop wordpress
# 	docker rm wordpress
# 	docker image rm wordpress

# webclean:
# 	make nginx_fclean
# 	make wordpress_fclean
# 	sudo rm -rf $(VOLUME_WEB)

re:
	make fclean || true
	make all

.PHONY = mariadb nginx wordpress all clean fclean re 
