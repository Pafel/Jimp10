aprox_tryg: main.o splines_t.o points.o apr_tryg.o
	$(CC) -o aprox_tryg  main.o splines_t.o points.o apr_tryg.o -lm

apr_tryg.o: makespl.h points.h
	$(CC) -c apr_tryg.c

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta
