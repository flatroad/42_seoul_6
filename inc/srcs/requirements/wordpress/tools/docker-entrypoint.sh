#!/bin/sh
set -eo pipefail
if [ ! -e wp-config.php ]; then
  wp core download --path=/var/www/html --allow-root
  wp config create \
    --dbname=$MYSQL_DATABASE \
    --dbuser=$MYSQL_USER \
    --dbpass=$MYSQL_USER_PASSWORD \
    --dbhost=$WORDPRESS_DB_HOST
  wp core install \
    --url=$WP_URL \
    --title=$WP_TITLE \
    --admin_user=$WP_ADMIN \
    --admin_password=$WP_ADMIN_PASSWORD \
    --admin_email=$WP_ADMIN_EMAIL \
    --skip-email
  wp user create user1 user1@42.fr --role=author --user_pass=$WP_USER_PASSWORD
fi

#데이터베이스에서 유저 권한 보는 쿼리
#mysql -u mysql -p
# passwd 입력
#show databases;
#use ft_wordpress;
#select meta_key, meta_value from wp_usermeta where meta_key='wp_capabilities';

php-fpm81 -F