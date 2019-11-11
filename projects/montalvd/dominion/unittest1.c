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
    int k[10] = {baron, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    printf ("Starting unit Test 1.\n");
    printf ("\n------------------------TESTING FOR DISCARD OF BARON CARD-----------------\n");
	int numPlayer = 2;
	int seed = 23;
	int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    G.handCount[p] = 5;
    G.hand[0][0] = baron;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = 0;
    int bonus = -1;
    cardEffect(baron, choice1, -1, -1, &G, 0, &bonus);
    assert(G.handCount[p] == 4);    

    return 0;
}

int test2(){
    struct gameState G;
    int k[10] = {baron, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    printf ("Starting Test 2.\n");
    printf ("\n------------------------TESTING FOR DECREMENT OF ESTATE CARD------------------------\n");
    int numPlayer = 2;
    int seed = 23;
    int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    G.supplyCount[estate] = 0;
    int p = 0;
    G.handCount[p] = 5;
    G.hand[0][0] = baron;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = 0;
    int bonus = -1;
    cardEffect(baron, choice1, -1, -1, &G, 0, &bonus);
    //assert(G.discardCount[0] == 1);
    assert(G.supplyCount[estate] == 0);    

    return 0;
}

int test3(){
    struct gameState G;
    int k[10] = {baron, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    printf ("Starting Test 3\n");
    printf ("\n------------------------TESTING FOR NO ESTATE CARD------------------------\n");
    int numPlayer = 2;
    int seed = 23;
    int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    G.handCount[p] = 5;
    G.hand[0][0] = baron;
    G.hand[0][1] = copper;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = 1;
    int bonus = -1;
    G.coins = 0;
    cardEffect(baron, choice1, -1, -1, &G, 0, &bonus);
    assert(G.numBuys == 2);    
    assert(G.coins == 0);

    return 0;
}

int test4(){
    struct gameState G;
    int k[10] = {baron, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    printf ("Starting Test 4.\n");
    printf ("\n------------------------TESTING FOR FINDING ESTATE IN HAND------------------\n");
    int numPlayer = 2;
    G.coins = 1;
    G.supplyCount[estate] = 10;
    int seed = 23;
    int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    G.handCount[p] = 4;
    G.hand[0][0] = estate;
    G.hand[0][1] = copper;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = baron;
    G.hand[0][5] = copper;
    int choice1 = 1;
    int bonus = -1;
    G.coins = 0;
    cardEffect(baron, choice1, -1, -1, &G, 0, &bonus);
    //assert(G.discardCount[0] == 1);
    assert(G.coins == 4);    

    return 0;
}



int main(){
	test1();
	test2();
	test3();
	test4();
}
