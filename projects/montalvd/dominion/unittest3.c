#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cardEffect( int, int, int, int, struct gameState*, int, int*);
void assert(bool exp){
	if(exp)
	    printf("\nAssertion true\n\n");
	else
	    printf("\nAssertion false\n\n");
}

int test1 () {
    struct gameState G;
    int k[10] = {baron, ambassador, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    printf ("Starting unit Test 1.\n");
    printf ("\n------------------------TESTING FOR NEGATIVE CHECK-----------------\n");
	int numPlayer = 2;
	int seed = 23;
	int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    int before = G.supplyCount[copper];
    G.handCount[p] = 5;
    G.hand[0][0] = ambassador;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = 2;
    int bonus = -1;
    cardEffect(ambassador, choice1, -1, -1, &G, 0, &bonus);
    assert(G.supplyCount[copper] == (before - 1));    

    return 0;
}

int test2(){
    struct gameState G;
    int k[10] = {baron, ambassador, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    printf ("Starting Test 2.\n");
    printf ("\n------------------------TESTING FOR ADDED CARD------------------------\n");
    int numPlayer = 2;
    int seed = 23;
    int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    G.handCount[p] = 5;
    G.hand[0][0] = ambassador;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = 2;
    int bonus = -1;
    cardEffect(ambassador, choice1, 1, -1, &G, 0, &bonus);
    assert(G.discard[1][0] == copper);    
    return 0;
}


int main(){
	test1();
	test2();
}
