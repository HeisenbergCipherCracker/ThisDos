CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = your_executable_name

all: $(TARGET)

$(TARGET): thisdos.c
    $(CC) $(CFLAGS) -o $@ $<

clean:
    rm -f $(TARGET)
