#!/bin/bash
rm get_next_line_array*.o
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line_array*.c
gcc -o array get_next_line_array*.o
./array

