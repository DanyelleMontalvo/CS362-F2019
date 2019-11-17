#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern int tributeRevealedCards[];

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

    printf ("Starting unit Test 4.\n");
    printf ("\n------------------------TESTING FOR INITIALIZATION-----------------\n");
	int numPlayer = 2;
	int seed = 23;
	int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    G.coins = 0;
    tributeRevealedCards[0] = copper;
    tributeRevealedCards[1] = estate;
    G.deckCount[1] = 1;
    G.handCount[p] = 5;
    G.hand[0][0] = tribute;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = -1;
    int bonus = -1;
    cardEffect(tribute, choice1, -1, -1, &G, 0, &bonus);
    //assert(G.coins == 2);    
    assert(tributeRevealedCards[1] == -1);

    return 0;
}

int test2(){
    struct gameState G;
    int k[10] = {baron, ambassador, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

    //printf ("Starting Test 2.\n");
    printf ("\n----------TESTING FOR RANDOMNESS-----------\n");
    int numPlayer = 2;
    int seed = 23;
    int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    G.deckCount[1]= 0;
    G.discardCount[1] = 3;
    int before = G.deck[1][0];
    G.handCount[p] = 5;
    G.hand[0][0] = tribute;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = -1;
    int bonus = -1;
    cardEffect(tribute, choice1, -1, -1, &G, 0, &bonus);
    assert(G.discard[1][0] != before);    
    return 0;
}

int test3() {
    struct gameState G;
    int k[10] = {baron, ambassador, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy
                };

   // printf ("Starting unit Test 3.\n");
    printf ("\n------TESTING FOR CHOICES-------\n");
	int numPlayer = 2;
	int seed = 23;
	int r;
    memset(&G, 23, sizeof(struct gameState));
    r = initializeGame(numPlayer, k, seed, &G);
    int p = 0;
    G.coins = 0;
    tributeRevealedCards[0] = copper;
    tributeRevealedCards[1] = baron;
    G.deckCount[1] = 3;
    G.deck[1][0] = baron;
    G.deck[1][1] = copper;
    G.deck[1][2] = baron;	
    //G.handCount[p] = 5;
    int before = G.coins;
    int beforeact = G.numActions;
    G.hand[0][0] = tribute;
    G.hand[0][1] = estate;
    G.hand[0][2] = copper;
    G.hand[0][3] = copper;
    G.hand[0][4] = copper;
    int choice1 = -1;
    int bonus = -1;
    cardEffect(tribute, choice1, -1, -1, &G, 0, &bonus);
    printf("\nTribute revealed card 1 is %d\n", tributeRevealedCards[0]);
    printf("\nTribute revealed card 2 is %d\n", tributeRevealedCards[1]);
    assert(G.coins == (before + 2));    
    assert(G.numActions == (beforeact + 2));

    return 0;
}

int main(){
	test1();
	test2();
	test3();
}
