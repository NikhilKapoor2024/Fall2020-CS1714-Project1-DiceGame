#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

/* Nikhil Kapoor -Project 1 - CS 1714
   This program simulates a 2-player dice game that asks the user to enter the number of rounds to play, then
   creates a dynamically allocated array with variables from a struct and a enumerator. By the end of the last round, the
   points are compared and the player with the most points wins. Edits have been made as of 3/17/2022 to avoid any copyright
   issues and such. */

int main(int argc, char* argv[]) {

    srand(time(NULL)); // initializes srand to begin randomizer
    int pOneScore = 0; // Player 1 score
    int pTwoScore = 0; // Player 2 score
    int currPlayer = (rand() % 2) + 1;
    DiceRound* diceRound = NULL;
    int numRounds; // number of Rounds
    int i;
    printf("Enter the number of rounds: ");
    scanf("%d", &numRounds);
    diceRound = (DiceRound*)malloc(sizeof(DiceRound) * numRounds);
    if (diceRound == NULL) {
        return 1;
    }
    
    printPlayerInfo(pOneScore, pTwoScore);

    for (i = 0; i < numRounds; i++) {
        fillRounds(diceRound, numRounds);
        printf("\nROUND %d\n--------\n", (i + 1));
        printf("Player\t: %d\n", currPlayer);
        printRoundInfo(diceRound);
        if (currPlayer == 1) {
            if (diceRound->dice % 2 == 0) {
                pOneScore += getRoundPoints(diceRound);
            }
            else if (diceRound->dice % 2 != 0) {
                pOneScore -= getRoundPoints(diceRound);
                currPlayer = 2;
            }
        }
        else if (currPlayer == 2) {
            if (diceRound->dice % 2 != 0) {
                pTwoScore += getRoundPoints(diceRound);
            }
            else if (diceRound->dice % 2 == 0) {
                pTwoScore -= getRoundPoints(diceRound);
                currPlayer = 1;
            }
        }
        printPlayerInfo(pOneScore, pTwoScore);
    }
    
    printf("\nGAME OVER!!\n");
    if (pOneScore > pTwoScore) {
        printf("P1 Won\n");
    }
    else {
        printf("P2 Won\n");
    }

    free(diceRound);

    return 0;
}
