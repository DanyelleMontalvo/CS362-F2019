#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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
    G.hand[0][1] = (rand()%(26-1+1)) + 1;
    G.hand[0][2] = (rand()%(26-1+1)) + 1;
    G.hand[0][3] = (rand()%(26-1+1)) + 1;
    G.hand[0][4] = (rand()%(26)) + 1; 
    printf("\nPlayer's hand is:\n%d\n%d\n%d\n%d\n%d\n", G.hand[0][0], G.hand[0][1], G.hand[0][2], G.hand[0][3], G.hand[0][4]);
    int choice1 = (rand()%2);
    printf("\nChoice is equal to: %d\n", choice1);
    int bonus = -1;
    cardEffect(baron, choice1, -1, -1, &G, 0, &bonus);
    assert(G.handCount[p] == 4);    
  
    return 0;
}


int main(){
	srand(time(NULL));
	for(int i = 0; i <= 100; i++){
		test1();
	}
}
