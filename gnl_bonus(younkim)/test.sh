#!/bin/bash
gcc -D BUFFER_SIZE=42 -Wextra -Werror -Wall -c main.c get_next_line.c get_next_line_utils.c
gcc main.o get_next_line.o get_next_line_utils.o
./a.out
