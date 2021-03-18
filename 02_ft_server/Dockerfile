FROM debian:buster
LABEL maintainer="jaeskim <jaeskim.student.42seoul.kr>"

# init arg
ARG WP_DB_NAME=wordpress
ARG WP_DB_USER=jaeskim
ARG WP_DB_PASSWORD=42seoul

# port setup
EXPOSE 80/tcp 443/tcp

# init setup
RUN apt update -y; apt upgrade -y

# install dependency
RUN apt install nginx php-fpm mariadb-server php-mysql php-mbstring vim curl -y

# copy src files
COPY srcs /

# setup SSL
RUN openssl genrsa -out ft_server.localhost.key 4096; \
	openssl req -x509 -nodes -days 365 \
	-key ft_server.localhost.key \
	-out ft_server.localhost.crt \
	-subj "/C=KR/ST=SEOUL/L=Gaepo-dong/O=42Seoul/OU=jaeskim/CN=localhost"; \
	chmod 644 ft_server.localhost.*; \
	mv ft_server.localhost.crt /etc/ssl/certs/;	\
	mv ft_server.localhost.key /etc/ssl/private/; \
	cp /nginx-sites-available-default.conf /etc/nginx/sites-available/default

# setup mysqlDB(mariaDB)
RUN service mysql start; \
	mysql -e "CREATE DATABASE ${WP_DB_NAME};\
	USE ${WP_DB_NAME}; \
	CREATE USER '${WP_DB_USER}'@'localhost' IDENTIFIED BY '${WP_DB_PASSWORD}'; \
	GRANT ALL PRIVILEGES ON ${WP_DB_NAME}.* TO '${WP_DB_USER}'@'localhost' WITH GRANT OPTION; \
	FLUSH PRIVILEGES;"

# chage directory owner
RUN chown -R www-data:www-data /var/www/html/

# setup nginx running forground
# RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

ENTRYPOINT ["/bin/bash", "-C", "/server.sh"]
