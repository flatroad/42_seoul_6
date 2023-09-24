FROM alpine:3.18.2

EXPOSE 443

# RUN <<EOT
RUN set -ex && \
	apk update  && \
	apk add nginx && \
	apk add openssl && \
	apk add sudo && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt -subj="/CN=sounchoi.42.fr"


COPY conf/default.conf /etc/nginx/http.d/

# CMD tail -f /dev/null
CMD nginx -g "daemon off;"
