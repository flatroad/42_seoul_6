FROM alpine:3.18.2

EXPOSE 443

COPY conf/nginx.conf /etc/nginx/http.d/default.conf

# COPY "./conf/nginx.conf" "/etc/nginx/conf.d/default.conf"
COPY "./tools/docker-entrypoint.sh" "/docker-entrypoint.sh"

RUN apk update &&\
	apk add --no-cache openssl curl ca-certificates &&\
  apk add nginx && \
  mkdir -p /etc/nginx/certs && \
  openssl req -x509 -new \
    -newkey rsa:2048 \
    -keyout /etc/nginx/certs/nginx.key  \
    -out /etc/nginx/certs/nginx.crt  \
      -subj "/CN=$COMMON_NAME"  \
      -days 365 \
      -nodes && \
  chmod +x /docker-entrypoint.sh 

ENTRYPOINT ["/docker-entrypoint.sh"]


	# printf "%s%s%s%s\n" \
  #   "@nginx " \
  #   "http://nginx.org/packages/alpine/v" \
  #   `egrep -o '^[0-9]+\.[0-9]+' /etc/alpine-release` \
  #   "/main" \
  #   | tee -a /etc/apk/repositories && \
  # curl -o /etc/apk/keys/nginx_signing.rsa.pub https://nginx.org/keys/nginx_signing.rsa.pub && \
  # apk add nginx@nginx && \