#!/bin/bash

# 모든 도커 컨테이너를 중지하고 삭제합니다.
docker stop $(docker ps -a -q)
docker rm $(docker ps -a -q)

# 모든 도커 이미지를 삭제합니다.
docker rmi $(docker images -q)

# 사용하지 않는 도커 네트워크를 삭제합니다.
docker network prune -f

# 사용하지 않는 볼륨을 삭제합니다.
docker volume prune -f
