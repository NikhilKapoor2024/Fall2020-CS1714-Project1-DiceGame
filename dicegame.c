#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

/* getRandomNumber() function: will take in two integer parameters (min,
    max), inclusive, and returns a random integer from that range  */
int getRandomNumber(int numMin, int numMax) {

    int randNum;
    
    randNum = (rand() % numMax) + numMin;

    return randNum;

}

/* fillRounds() function: fills DiceRound array by allocating all 3 of its
    members: 'dice', 'points', 'type' */
void fillRounds(DiceRound* round, int size) {
    int i;

    for (i = 0; i < size; ++i) {
        round[i].dice = getRandomNumber(1, 6);
        round[i].points = 10 * getRandomNumber(1, 10);
        round[i].RoundType = getRandomNumber(1, 5);
    }

}

/* getRoundPoints() function: generates points for the round based on type of round and number rolled */
int getRoundPoints(DiceRound* r) {
    
    int actualPoints = 0;

    switch(r->RoundType) {
        case BONUS:
        actualPoints = 100;
        break;
        case DOUBLE:
        actualPoints = r->points * 2;
        break;
        default:
        actualPoints = r->points;
        break;
    }

    return actualPoints;
}

/* printRoundInfo() function: prints the current round information */
void printRoundInfo(DiceRound* rPtr) {
   
   switch(rPtr->RoundType) {
        case BONUS:
        printf("TYPE\t: BONUS\n");
        break;
        case DOUBLE:
        printf("TYPE\t: DOUBLE\n");
        break;
        default:
        printf("TYPE\t: REGULAR\n");
        break;
    }

    printf("Dice\t: %d\n", rPtr->dice);
    printf("Points\t: %d\n", rPtr->points);
    
}

/* printPlayerInfo() function: will print points for both players  */
void printPlayerInfo(int playerOnePoints, int playerTwoPoints) {

    printf("P-1\t: %d\n", playerOnePoints);
    printf("P-2\t: %d\n", playerTwoPoints);

}
