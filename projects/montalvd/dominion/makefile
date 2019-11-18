unittestresults: unittest1.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.c rngs.c -lm -c
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o randomtestcard1.c -lm -o randomtestcard1 
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o randomtestcard2.c -lm -o randomtestcard2
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o randomtestcard3.c -lm -o randomtestcard3 
	-./randomtestcard1 > ut1.out
	-./randomtestcard2 > ut2.out
	-./randomtestcard3 > ut3.out
	gcov -b -f dominion.c > gcov.out
	cat ut1.out ut2.out ut3.out gcov.out > unittestresults.out
		

	
