#!/bin/sh

export MYSQL_ROOT=root
export MYSQL_ROOT_PASSWORD=passwd
export MYSQL_USER=mysql
export MYSQL_PASSWORD=passwd
export MYSQL_DATABASE=ft_wordpress

apk update
apk add mariadb mariadb-client
