FROM alpine:3.15

RUN apk --update add --no-cache --virtual .builddeps \
    mariadb \
    mariadb-client \
    mariadb-server-utils

EXPOSE 3306
COPY   tools/db_start.sh /usr/local/bin/

RUN    chmod 755 /usr/local/bin/db_start.sh

ENTRYPOINT ["sh", "/usr/local/bin/db_start.sh"]
