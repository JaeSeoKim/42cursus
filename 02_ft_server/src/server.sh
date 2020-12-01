#!/bin/bash

/bin/bash -C /setup_autoindex.sh $1

service mysql start
service php7.3-fpm start
service nginx start

if [ $? -eq 0 ]; then
	tail -f /var/log/nginx/access.log /var/log/nginx/error.log
fi
