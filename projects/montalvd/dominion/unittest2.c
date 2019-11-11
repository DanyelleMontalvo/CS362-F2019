#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void drawCard(int, struct gameState*);
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
    printf ("\n------------------------TESTING FOR DISCARD OF HAND-----------------\n");
	int numPlayer = 2;
	int seed = 23;
	int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
//    for (int k = 0; k < 4; k++)
//	drawCard(1, &G);
    int p = 0;
   // int before = G.hand[1][0];
    G.handCount[p] = 5;
    G.hand[0][0] = minion;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = 0;
    int bonus = -1;
    cardEffect(minion, choice1, 1, -1, &G, 0, &bonus);
   // assert(G.hand[1][0] == before);    

    return 0;
}

int test2(){
    struct gameState G;
    int k[10] = {baron, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    printf ("Starting Test 2.\n");
    printf ("\n------------------------TESTING FOR DISCARD OF MINION CARD------------------------\n");
    int numPlayer = 2;
    int seed = 23;
    int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    G.supplyCount[estate] = 0;
    int p = 0;
    G.handCount[p] = 5;
    G.hand[0][0] = minion;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = 0;
    int bonus = -1;
    cardEffect(minion, choice1, 1, -1, &G, 0, &bonus);
    //assert(G.discardCount[0] == 1);
    assert(G.handCount[0] == 3);    

    return 0;
}



int main(){
	test1();
	test2();
}
