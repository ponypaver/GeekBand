CC = g++
CFLAGS = -g -O3 -Wall

shape: rectangle.o circle.o shape.o
	${CC} ${CFLAGS} -o $@ $^
.c.o:
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -f *.o shape
