.PHONY: clean
all: shell
clean:
	rm -f *.o
shell: shell.o
	$(CXX) -o $@ $<
