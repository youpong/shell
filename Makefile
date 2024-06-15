CFLAGS = -std=c17 -Wall -Wextra --pedantic-errors
CXXFLAGS = -std=c++20 -Wall -Wextra --pedantic-errors

.PHONY: clean
all: shell
clean:
	rm -f *.o shell output
shell: shell.o error.o
	$(CC) -o $@ $^
