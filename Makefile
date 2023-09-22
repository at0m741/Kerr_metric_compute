PROG_NAME = kerr_compute

CC = gcc
CFLAGS = -Wall -g -Werror -Wextra
LIBS = -lgsl -lgslcblas -lm

SRCS = kerr_composant.c main.c geodesics_commons.c
OBJS = $(SRCS:.c=.o)

$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG_NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROG_NAME)

all: $(PROG_NAME)

.PHONY: clean
