unittestresults: unittest1.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.c rngs.c -lm -c
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o unittest1.c -lm -o unittest1 
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o unittest2.c -lm -o unittest2 
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o unittest3.c -lm -o unittest3  
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o unittest4.c -lm -o unittest4 
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o unittest5.c -lm -o unittest5
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o randomtestcard1.c -lm -o randomtestcard1
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o randomtestcard2.c -lm -o randomtestcard2
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.o rngs.o randomtestcard3.c -lm -o randomtestcard3
	-./unittest1 > ut1.out
	-./unittest2 > ut2.out
	-./unittest3 > ut3.out
	-./unittest4 > ut4.out
	-./unittest5 > ut5.out
	-./randomtestcard1 > rt1.out
	-./randomtestcard2 > rt2.out
	-./randomtestcard3 > rt3.out
	gcov -b -f dominion.c > gcov.out
	cat ut1.out ut2.out ut3.out ut4.out ut5.out rt1.out rt2.out rt3.out gcov.out > unittestresults.out
		

	
