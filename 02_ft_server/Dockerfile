FROM debian:buster
LABEL maintainer="jaeskim <jaeskim.student.42seoul.kr>"

# init setup
RUN apt update -y; apt upgrade -y

# install dependency
RUN apt install nginx vim curl -y

# copy src files
COPY src /

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

ENTRYPOINT ["/bin/bash", "-C", "/server.sh"]