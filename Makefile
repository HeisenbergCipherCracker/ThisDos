# Makefile for compiling thisdos.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Executable name
EXEC = thisdos

# Source files
SRCS = thisdos.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(EXEC)

# Compile rule
$(EXEC): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Rule to compile C source files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
    rm -f $(EXEC) $(OBJS)
