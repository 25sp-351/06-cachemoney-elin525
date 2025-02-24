CC = gcc
CFLAGS = -Wall -g
SRCS = main.c cache.c money_to_text.c
OBJS = $(SRCS:.c=.o)
TARGET = money_to_text

all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)