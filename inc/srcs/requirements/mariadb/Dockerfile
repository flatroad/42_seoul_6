#mariaDB
FROM alpine:3.18.2

WORKDIR /var/lib/mysql

EXPOSE 3306

COPY "tools/docker-entrypoint.sh" "/docker-entrypoint.sh"
COPY "conf/my.cnf" "/etc/my.cnf.d/mariadb-server.cnf"

RUN set -ex && \
  apk update && \
  apk add  --no-cache mariadb mariadb-client  && \
  chmod +x /docker-entrypoint.sh

  # apk add  --no-cache mariadb mariadb-client openrc vim && \

ENTRYPOINT ["/docker-entrypoint.sh"]
