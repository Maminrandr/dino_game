#!/bin/bash
gcc  *.c -g -I./include -L ./lib -lraylib -lm -ldl -lpthread -lGL -lrt -lX11; \
export	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib; ./a.out;
