#!/bin/sh

set -xe

# CC=clang
# CFLAGS="-Wall -Wextra -std=c11 -pedantic -ggdb -fsanitize=memory"

CC=gcc
CFLAGS="-Wall -Wextra -std=c11 -pedantic -ggdb"

$CC $CFLAGS -o main main.c
