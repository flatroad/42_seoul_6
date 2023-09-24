#!/bin/bash

docker build -t test MariaDB/.
docker run -d -p 3306:3306 test
docker ps -a