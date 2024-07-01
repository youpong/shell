TARGET = shell
SRCS = shell.c error.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -std=c17 -Wall -Wextra --pedantic-errors
CXXFLAGS = -std=c++20 -Wall -Wextra --pedantic-errors

.PHONY: clean
all: $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET) output
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
