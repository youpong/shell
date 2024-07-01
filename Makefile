TARGET = shell
SRCS = shell.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean
all: $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) -o $@ $<
