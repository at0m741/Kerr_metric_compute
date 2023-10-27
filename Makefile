PROG_NAME = kerr_compute


MLX = ./mlx_linux/libmlx.a

MLX_SUBDIR = ./mlx_linux

CC = gcc
CFLAGS = -Wall -g -Werror -Wextra

LIBS = -lgsl -lgslcblas -lm -lGL -lGLU -lglut

SRCS = kerr_composant.c main.c geodesics_commons.c kerr_matrix.c cristoffel.c
OBJS = $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_SUBDIR)

$(PROG_NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG_NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROG_NAME)

all: $(PROG_NAME)

.PHONY: clean
