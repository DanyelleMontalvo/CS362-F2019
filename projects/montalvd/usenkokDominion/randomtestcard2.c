#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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
    //for (int k = 0; k < 4; k++)
//	drawCard(1, &G);
    int p = 0;
   int before = G.hand[1][0];
    G.handCount[p] = 5;
    G.hand[0][0] = minion;
    G.hand[0][1] = (rand()%26) + 1;
    G.hand[0][2] = (rand()%26) + 1;
    G.hand[0][3] = (rand()%26) + 1;
    G.hand[0][4] = (rand()%26) + 1;
    printf("\nThe player's hand is: \n%d\n%d\n%d\n%d\n%d\n", G.hand[0][0], G.hand[0][1], G.hand[0][2], G.hand[0][3], G.hand[0][4]);
    int choice1 = rand()%2;
    int choice2;
    if(choice1 == 0)
	choice2 = 1;
    if(choice1 == 1)
	choice2 = 0;
    int bonus = -1;
    printf("\nChoice 1 is: %d\nChoice 2 is: %d\n", choice1, choice2);
    cardEffect(minion, choice1, choice2, -1, &G, 0, &bonus);
    printf("\nThe player's hand is NOW: \n%d\n%d\n%d\n%d\n%d\n", G.hand[0][0], G.hand[0][1], G.hand[0][2], G.hand[0][3], G.hand[0][4]);
     
    assert(G.hand[1][0] != before);    

    return 0;
}

int main(){
	srand(time(NULL));
	for (int i = 1; i < 100; i++)
		test1();
	
}
