# 기본 이미지를 선택합니다.
FROM alpine:3.18.2

# 필요한 소프트웨어 설치
RUN apk update
RUN apk --no-cache add \
    php82 \
    php82-fpm \
    php82-mysqli \
    php82-json \
    php82-openssl \
    php82-curl \
    php82-zlib \
    php82-xml \
    php82-phar \
    php82-intl \
    php82-dom \
    php82-xmlreader \
    php82-ctype \
    php82-mbstring \
    php82-gd \
    php82-session

# WordPress 소스 코드 다운로드 및 설정
WORKDIR /usr/share/nginx/html
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    rm latest.tar.gz && \
    mv wordpress/* . && \
    rmdir wordpress && \
    cp wp-config-sample.php wp-config.php && \
    sed -i 's/database_name_here/your_db_name/g' wp-config.php && \
    sed -i 's/username_here/your_db_user/g' wp-config.php && \
    sed -i 's/password_here/your_db_password/g' wp-config.php

# PHP-FPM 실행 파일의 경로를 지정합니다.
CMD ["/usr/sbin/php-fpm82", "-F"]



#https://developer.wordpress.org/advanced-administration/before-install/howto-install/
#https://developer.wordpress.org/advanced-administration/wordpress/wp-config/
#https://httpd.apache.org/docs/current/mod/core.html#documentroot