CC = cc
CFLAGS = -Wall -Wextra -Wpedantic -g
LIBRARIES = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = output
SRC = main.c

# Default target
all: compile

# Compile the C program
compile:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBRARIES)

release:
	$(CC) $(CFLAGS) -O3 -s -o $(TARGET) $(SRC) $(LIBRARIES)

# Run the compiled output
run: compile
	./$(TARGET)

# Delete the output file
clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts with file names
.PHONY: all compile run clean
