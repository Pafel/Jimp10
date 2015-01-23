aprox: main.o splines.o splines_n.o points.o aproksymator_na_bazie.o apr_tryg.o gaus/libge.a
	$(CC) -o aprox  main.o splines.o splines_n.o points.o aproksymator_na_bazie.o apr_tryg.o -L gaus -l ge -lm

intrp: main.o splines.o points.o interpolator.o gaus/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L gaus -l ge

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator_na_bazie.c

interpolator.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c interpolator.c

apr_tryg.o: splines_n.h points.h
	$(CC) -c apr_tryg.c
.PHONY: clean

clean:
	-rm *.o aprox intrp prosta
