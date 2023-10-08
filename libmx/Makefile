FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
CC = clang

name = libmx.a

all: $(name)

$(name):
	mkdir obj/
	$(CC) $(FLAGS) -c src/*.c
	mv *.o obj/
	ar rcs $(name) obj/*.o
clean:
	rm -rf obj/

uninstall:
	rm -f $(name)

reinstall:
	make clean
	make uninstall
	make all
