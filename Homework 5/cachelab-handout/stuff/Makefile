#
# Student makefile for Cache Lab
#
CC = gcc
CFLAGS = -g -Wall -Werror -std=c99

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c

        $(CC) $(CFLAGS)  -o $@ $<
clean:
	rm $(PROGS)