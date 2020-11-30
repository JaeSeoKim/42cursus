#!/bin/bash

# setup index.html
if [ -f "/var/www/html/index.nginx-debian.html" ]; then
	mv /var/www/html/index.nginx-debian.html /var/www/html/index.html
fi

if [ "$1" == "autoindex" ]; then
	echo "autoindex on!"
	sed -i "s@autoindex off;@autoindex on;@g" /etc/nginx/sites-available/default
	sed -i "s@index index.html index.htm;@index index.htm;@g" /etc/nginx/sites-available/default
else
	echo "autoindex off!"
	sed -i "s@autoindex on;@autoindex off;@g" /etc/nginx/sites-available/default
	sed -i "s@index index.htm;@index index.html index.htm;@g" /etc/nginx/sites-available/default
fi
