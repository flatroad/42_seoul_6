#!/bin/sh
set -ex
mkdir -p /home/younkim/inception
mount -t vboxsf inception /home/younkim/inception
apt-get update
apt-get install vim ssh sudo curl -y
usermod -a -G sudo younkim
usermod -a -G root younkim