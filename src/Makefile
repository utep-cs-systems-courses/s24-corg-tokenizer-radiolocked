#for convenience, define variable $(OBJS) to list of object files
OBJS = history.o tokenizer.o uimain.o

CFLAGS=-g -O3

all: main

main: $(OBJS)
	cc -o main $(CFLAGS) $(OBJS)

$(OBJS): history.h tokenizer.h

clean:
	rm -f *.o main

run: main
	./main
