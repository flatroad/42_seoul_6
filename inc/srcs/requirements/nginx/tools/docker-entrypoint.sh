#!/bin/sh
# set -ex
# mkdir -p /etc/nginx/certs && \
# openssl req -x509 -new \
#   -newkey rsa:2048 \
#   -keyout /etc/nginx/certs/nginx.key  \
#   -out /etc/nginx/certs/nginx.crt  \
#         -subj "/CN=$COMMON_NAME"  \
#         -days 365 \
#         -nodes

	# openssl req -new -newkey rsa:2048 -nodes -keyout <개인키이름>.key -out <인증요청서이름>.csr
	# req : 새로운 인증서(Certificate) 및 인증서 요청(Certificate Request)을 생성하는 명령어입니다
  # x509 : ITU-T X.509 표준에 따라 인증서의 형식을 지정합니다.
  # -new : 새로운 CSR(Certificate Signing Request)을 생성할 때 사용됩니다.
  #      : 이 옵션을 사용하면 OpenSSL은 새로운 개인키와 함께 새로운 CSR을 생성합니다.
	# -newkey: 새로운 개인키 및 공개키를 생성합니다.
  # -keyout: 개인키 파일을 지정합니다.(생성된 개인키는 PEM형식으로 저장됩니다, 파일 부재시 stdout으로 출력됩니다.)
  # -key : 비밀키 파일에서 비밀키를 추출하거나 변환하는데 사용된다
	# -out: 인증서 또는 인증서 요청 파일을 지정합니다.
	# -days: 인증서의 유효기간을 일(day) 단위로 지정합니다.
	# -config: OpenSSL 설정 파일의 경로를 지정합니다.
	# -subj: 인증서 또는 인증서 요청의 주체 정보를 지정합니다.(부재시 대화형으으로 정보를 물어봅니다)
	# -nodes :  개인 키 파일의 암호화를 제거합니다. 
  #        :  개인 키 파일에는 일반적으로 공개 키와 함께 사용자가 자신의 서버에서 사용하는 공개 및 개인 SSL/TLS 인증서가 포함되어 있습니다. 
  #        :  일반적으로 이 옵션은 개발 및 테스트 목적으로만 사용됩니다.

nginx -g 'daemon off;'