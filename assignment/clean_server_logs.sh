#!/bin/bash

FILE="server_access.log"

if [ ! -f "$FILE" ]; then
    echo "Error: $FILE not found."
    exit 1
fi

sed -E -i \
    -e '/^#/d' \
    -e 's/HTTP\/1\.0/HTTP\/1.1/g' \
    -e 's/[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}/XXXX-XXXX-XXXX-XXXX/g' \
    -e 's/[0-9]{16}/XXXX-XXXX-XXXX-XXXX/g' \
    "$FILE"

echo "Log file cleaned successfully."