OBJS	= thisdos.o
SOURCE	= thisdos.c
HEADER	= 
OUT	= thisdos
LFLAGS	 = -lpthread -lstdc++

all: thisdos

thisdos: $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)
