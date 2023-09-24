#!/bin/sh

mysql_install_db
/usr/share/mariadb/mysql.server start
mariadb -e "
    CREATE DATABASE $MYSQL_DATABASE; \
    CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD'; \
    GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_USER_PASSWORD' WITH GRANT OPTION; \
    GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD' WITH GRANT OPTION; \
    FLUSH PRIVILEGES;"
mysqladmin --user=root --password=$MYSQL_ROOT_PASSWORD shutdown
mysqld_safe