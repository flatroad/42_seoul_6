FROM alpine:3.18.2

EXPOSE 9000

ENV MYSQL_ROOT "root"
ENV MYSQL_ROOT_PASSWORD "passwd"
ENV MYSQL_USER "mysql"
ENV MYSQL_USER_PASSWORD "passwd"
ENV MYSQL_DATABASE "wordpress"

VOLUME [ "/var/lib/mysql" ]

RUN apk update && \
	apk add


ENTRYPOINT [ "/entrypoint.sh" ]