OBJS	= thisdos.o
SOURCE	= thisdos.c
HEADER	= 
OUT	= thiddos
LFLAGS	 = -lpthread

all: thiddos

thiddos: $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)