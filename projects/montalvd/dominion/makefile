unittestresults: unittest1.c
	gcc -std=c99 -fprofile-arcs -ftest-coverage dominion.c rngs.c unittest1.c -o unittest1 
	-./unittest1 > ut1.out 
	gcc -fprofile-arcs -ftest-coverage dominion.c rngs.c unittest2.c -o unittest2 
	-./unittest2 > ut2.out
	gcc -fprofile-arcs -ftest-coverage dominion.c rngs.c unittest3.c -o unittest3 
	-./unittest3 > ut3.out
	gcc -fprofile-arcs -ftest-coverage dominion.c rngs.c unittest4.c -o unittest4 
	-./unittest4 > ut4.out
	gcc -fprofile-arcs -ftest-coverage dominion.c rngs.c unittest5.c -o unittest5
	-./unittest5 > ut5.out
	gcov -b -f dominion.c > gcov.out
	cat ut1.out ut2.out ut3.out ut4.out ut5.out gcov.out > unittestresults.out
		

	
