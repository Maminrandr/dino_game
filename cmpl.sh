#!/bin/bash
gcc  *.c -g -I./include -L ./lib -lraylib -lm -ldl -lpthread -lGL -lrt -lX11 func_/show_position.c; \
export	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib; ./a.out; rm a.out;
