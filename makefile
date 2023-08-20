
CC = g++
CFlAGS = -I
DEPS = Node.hpp Tree.hpp


OBJS = Node.o Tree.o main.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

binom: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o binom

.PHONY: clean

clean: $(OBJS)
	rm -f $(OBJS) binom.exe
