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

# setup Wordpress
RUN tar -xzf wordpress.tar.gz -C /var/www/html/; \
	mv /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpress/wp-config.php; \
	sed -i "s/database_name_here/${WP_DB_NAME}/g" /var/www/html/wordpress/wp-config.php; \
	sed -i "s/username_here/${WP_DB_USER}/g" /var/www/html/wordpress/wp-config.php; \
	sed -i "s/password_here/${WP_DB_PASSWORD}/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'AUTH_KEY',         'put your unique phrase here' );/define( 'AUTH_KEY', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'SECURE_AUTH_KEY',  'put your unique phrase here' );/define( 'SECURE_AUTH_KEY', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'LOGGED_IN_KEY',    'put your unique phrase here' );/define( 'LOGGED_IN_KEY', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'NONCE_KEY',        'put your unique phrase here' );/define( 'NONCE_KEY', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'AUTH_SALT',        'put your unique phrase here' );/define( 'AUTH_SALT', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'SECURE_AUTH_SALT', 'put your unique phrase here' );/define( 'SECURE_AUTH_SALT', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'LOGGED_IN_SALT',   'put your unique phrase here' );/define( 'LOGGED_IN_SALT', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	wp_salt=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#\%+=' | fold -w 64 | sed 1q); \
	sed -i "s/define( 'NONCE_SALT',       'put your unique phrase here' );/define( 'NONCE_SALT', '$wp_salt' );/g" /var/www/html/wordpress/wp-config.php; \
	unset wp_salt

# setup phpmyadmin
RUN curl -O https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
RUN tar -xzf phpMyAdmin-5.0.4-all-languages.tar.gz -C /var/www/html/; \
	mv /var/www/html/phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin; \
	mv /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php; \
	blowfish_secret=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9!@#+=' | fold -w 64 | sed 1q); \
	sed -i "s@''; /\* YOU MUST FILL IN THIS FOR COOKIE AUTH! \*/@'$blowfish_secret';@g" /var/www/html/phpmyadmin/config.inc.php; \
	unset blowfish_secret;

# chage directory owner
RUN chown -R www-data:www-data /var/www/html/

# setup nginx running forground
# RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

ENTRYPOINT ["/bin/bash", "-C", "/server.sh"]
