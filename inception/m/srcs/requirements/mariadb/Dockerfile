FROM alpine:3.18.2

EXPOSE 3306

COPY conf/mariadb-server.conf /etc/my.cnf.d/mariadb-server.cnf
COPY tools/entrypoint.sh /

RUN apk update && apk add mariadb mariadb-client && chmod +x /entrypoint.sh


ENTRYPOINT [ "/entrypoint.sh" ]