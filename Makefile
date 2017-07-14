NAME = EscapeEarth
CC = clang++
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx
LDLIBS = -lmlx -framework OpenGL -framework AppKit
CFLAGS += -Iinclude/ -Iminilibx
ARCH = -arch i386

FILENAMES = main.cpp GameData.cpp Clock.cpp helpers.cpp draw.cpp Player.cpp \
	image.cpp MlxManager.cpp

FNS = $(addprefix src/, $(FILENAMES))
OBJECTS = $(addprefix build/, $(FILENAMES:.cpp=.o))

all: $(NAME)

minilibx/libmlx.a:
	cd minilibx && make

images.o: images.asm
	nasm -f macho -o $@ $< -DDARWIN

$(NAME): $(OBJECTS) images.o minilibx/libmlx.a
	$(CC) $(LDFLAGS) $(LDLIBS) $(ARCH) -o $(NAME) $(OBJECTS) images.o

build/%.o: src/%.cpp | build
	$(CC) $(CFLAGS) $(ARCH) -o $@ -c $<

build:
	mkdir build/

clean:
	/bin/rm -rf build/
	/bin/rm -f images.o

fclean: clean
	cd minilibx && make clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
