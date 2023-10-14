FROM alpine:3.18.2

EXPOSE 9000

WORKDIR /var/www/html

COPY "./tools/docker-entrypoint.sh" "/docker-entrypoint.sh"

RUN set -ex && apk update && \
    apk add --no-cache\
        curl \
        mariadb-client \
        php81 \
        php81-fpm \
        php81-phar \
        php81-session \
        php81-json \
        php81-mysqli \
        php81-iconv \
        php81-mbstring \
        php81-tokenizer \
        php81-curl && \
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp && \
    sed -i 's/^listen = .*/listen = 0.0.0.0:9000/' /etc/php81/php-fpm.d/www.conf && \
    chmod +x /docker-entrypoint.sh

ENTRYPOINT ["/docker-entrypoint.sh"]