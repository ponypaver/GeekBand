shape: rectangle.o circle.o shape.o
	g++ -g $^ -o $@
.c.o:
	g++ -g -c -o $@ $<

clean:
	rm -f *.o shape
