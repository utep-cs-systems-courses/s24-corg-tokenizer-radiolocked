#for convenience, define variable $(OBJS) to list of object files
OBJS = history.o tokenizer.o uimain.o tester.o

CFLAGS=-g -O3

all: uimain

uimain: $(OBJS)
	cc -o uimain $(CFLAGS) $(OBJS)

$(OBJS): history.h tokenizer.h

clean:
	rm -f *.o uimain

run:uimain
	./uimain
