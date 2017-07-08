NAME = space_shooter
CC = clang++
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx
LDLIBS = -lmlx -framework OpenGL -framework AppKit
CFLAGS += -Iinclude/ -Iminilibx

FILENAMES = main.cpp

FNS = $(addprefix src/, $(FILENAMES))
OBJECTS = $(addprefix build/, $(FILENAMES:.cpp=.o))

all: $(NAME)

minilibx/libmlx.a:
	cd minilibx && make

$(NAME): $(OBJECTS) minilibx/libmlx.a
	$(CC) $(LDFLAGS) $(LDLIBS) -o $(NAME) $(OBJECTS)

build/%.o: src/%.cpp | build
	$(CC) $(CFLAGS) -o $@ -c $<

build:
	mkdir build/

clean:
	/bin/rm -rf build/

fclean: clean
	cd minilibx && make clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
