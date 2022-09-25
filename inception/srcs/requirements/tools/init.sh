#!/bin/bash

set -eu

VOLUME_PATH="/home/iyamada/data"

sudo sed -i -e 's/localhost/iyamada.42.fr/' /etc/hosts
sudo mkdir -p ${VOLUME_PATH}/mariadb
sudo mkdir -p ${VOLUME_PATH}/wordpress
