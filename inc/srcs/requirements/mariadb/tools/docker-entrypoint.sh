#!/bin/sh
# set
# -e: 쉘 스크립트에서 발생한 에러를 즉시 종료합니다.
# -x: 쉘 스크립트에서 실행한 명령어를 출력합니다.

# rm -f /var/run/mysqld/mysqld.sock
# mkdir -p /run/openrc
# mkdir -p /var/lib/mysql
# if [ $(ls -l /var/lib/mysql 2> /dev/null | grep wordpress | wc -l) -eq 0 ]; then
#   set -e && \
#   touch /run/openrc/softlevel && \
#   rc-status  && \
#   /etc/init.d/mariadb setup && \
#   chmod 755 "/etc/my.cnf.d/mariadb-server.cnf" && \
#   chown -R mysql /var/lib/mysql && \
#   chmod -R 755 /var/lib/mysql && \
#   rc-service mariadb start
#   chown -R mysql /var/run/mysqld && \

#   mariadb <<EOF
#     CREATE DATABASE $MYSQL_DATABASE;
#     CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';
#     GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_USER_PASSWORD' WITH GRANT OPTION;
#     GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD' WITH GRANT OPTION;
#     FLUSH PRIVILEGES;
# EOF
#   rc-service mariadb stop 
# fi

# mysqld --user=$MYSQL_USER


mysql_install_db
/usr/share/mariadb/mysql.server start
mariadb -e "
    CREATE DATABASE $MYSQL_DATABASE; \
    CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD'; \
    GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_USER_PASSWORD' WITH GRANT OPTION; \
    GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD' WITH GRANT OPTION; \
    FLUSH PRIVILEGES;"
mysqladmin --user=root --password=$MYSQL_ROOT_PASSWORD shutdown
mysqld --user=$MYSQL_USER