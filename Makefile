##############################################################################
# Makefile for BFS/DFS assignment
# CMP_SC 3050
# Spring 2024
# By Jim Ries (RiesJ@missouri.edu)
##############################################################################
CC = gcc
CPP = g++
CFLAGS = -Wall -Werror -c -g -std=c11 -I.
CPPFLAGS = -Wall -Werror -c -g -I.
LDFLAGS = -lm -lMUCSGraph -L.

default: test

%.o : %.c 
	@echo Compiling $^ 
	@$(CC) $(CFLAGS) $^

%.o : %.cc
	@echo Compiling $^ 
	@$(CPP) $(CPPFLAGS) $^

test : main.o BFS.o DFS.o Queue.o
	@echo Linking $@ 
	@$(CC) $^ $(LDFLAGS) -o $@

clean : 
	@rm -rf *.o
	@rm -rf test
	@echo All Clean!
