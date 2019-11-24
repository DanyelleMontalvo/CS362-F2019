#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
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
    G.deckCount[1]= rand()%3 + 1;
    G.discardCount[1] = 0;
    int p = 0;
    G.coins = 0;
//    tributeRevealedCards[0] = (rand()%26) + 1;
  //  tributeRevealedCards[1] = (rand()%26) + 1;
    G.deck[1][0] = rand()%26 + 1;
    G.deck[1][1] = rand()%26 + 1;
    G.deck[1][2] = rand()%26 + 1;
    printf("Player 2's deck is: %d, %d, %d\n", G.deck[1][0], G.deck[1][1], G.deck[1][2]);
    G.handCount[p] = 5;
    G.hand[0][0] = tribute;
    G.hand[0][1] = (rand()%26) + 1;;
    G.hand[0][2] = rand()%26 + 1;
    G.hand[0][3] = rand()%26 + 1;
    G.hand[0][4] = rand()%26 + 1;
    int choice1 = -1;
    int bonus = -1;
    cardEffect(tribute, choice1, -1, -1, &G, 0, &bonus);
    //assert(G.coins == 2);    
    //printf("\nTribute revealed cars are: %d and %d\n", tributeRevealedCards[0], tributeRevealedCards[1]);
    //assert(tributeRevealedCards[1] == -1);

    return 0;
}

int main(){
	//srand(time(NULL));
	//for (int i = 0; i < 10000; i++)
	//	test1();
//	test2();
//	test3();
}
