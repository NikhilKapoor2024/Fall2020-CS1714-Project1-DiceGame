/* Header Guards  */
#ifndef DICEGAME_H
#define DICEGAME_H


/* ROUNDTYPE enumerator */
typedef enum ROUNDTYPE {
    BONUS,
    DOUBLE,
    REGULAR
} ROUNDTYPE;

/*  DiceRound struct */
typedef struct DiceRound_struct {
    int dice;
    int points;
    ROUNDTYPE RoundType;
} DiceRound;

/*---------- Function prototypes ---------- */

/*
    Function: getRandomNumber
    ---------------------------
    Generates a random number from a minumum to a maximum value,
    inclusive.
    min: minumum number
    max: maximum number
      Returns: random integer
*/
int getRandomNumber(int, int);

/*

    Function: fillRounds
    ----------------------
    Allocates the dice roll, number of points, and round type into
    a dynamic array
         array: array for storing the three members
         size: integer for the array size
         Returns: Nothing (void).
*/
void fillRounds(DiceRound*, int);

/*
    Function: getRoundPoints
    --------------------------
    Uses the 'type' of round and 'points' to determine the actual points
    for the round to be used.
        DiceRound: object for entire array
        Returns: integer value of points
*/
int getRoundPoints(DiceRound*);

/*
    Function: printRoundInfo
    --------------------------
    Prints the current type, dice, and points for the game
        DiceRound: object for the current round
        Returns: Nothing (void)
*/
void printRoundInfo(DiceRound*);

/*
    Function: printPlayerInfo
    ---------------------------
    Prints each of the player's points accumulated
        playerOnePoints: holds points for player 1
        playerTwoPoints: holds points for player 2
        Returns: Nothing (void)
*/
void printPlayerInfo(int, int);

#endif
