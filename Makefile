.PHONY: clean
all: shell
clean:
	rm -f *.o shell output
shell: shell.o error.o
	$(CC) -o $@ $^
