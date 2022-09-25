#!/bin/bash

set -eu

VOLUME_PATH="/home/iyamada/data"

sudo rm -rf ${VOLUME_PATH}/mariadb/* ${VOLUME_PATH}/wordpress/*
sudo sed -i -e 's/iyamada.42.fr/localhost/' /etc/hosts
