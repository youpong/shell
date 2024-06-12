.PHONY: clean
all: shell
clean:
	rm -f *.o
shell: shell.o error.o
	$(CXX) -o $@ $^
