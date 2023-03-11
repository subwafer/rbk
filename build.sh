#!/usr/bin/env sh

set -xe

CC=clang
CFLAGS="-Wall -Wextra -std=c11 -pedantic -ggdb"
# CFLAGS="-Wall -Wextra -std=c11 -pedantic -ggdb -fsanitize=memory"

$CC $CFLAGS -o rbk main.c
