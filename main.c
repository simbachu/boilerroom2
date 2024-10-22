#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define NUM_OF_DICE 5

typedef struct dice
{
    bool hold[NUM_OF_DICE];
    int value[NUM_OF_DICE];
}Dice;

enum Combinations {
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    PAIRS,
    DOUBLE_PAIR,
    TRIPLES,
    QUADRUPLETS,
    SMALL_LADDER,
    BIG_LADDER,
    FULL_HOUSE,
    CHANCE,
    YAHTZEE
};

struct scorecard{
    int category[2][15];
};

struct gamestate{
    int turn_number;
    struct scorecard player;
};

int roll_a_dice();

void take_turn();

int main()
{
    srand(time(NULL));          // seed random generator
    Dice main_dice;

    struct gamestate Game;
    int turns = 13;
    while ( Game.turn_number < turns )
    {
        take_turn();
    }
}

int roll_a_dice()
{
    return (rand() % 6) + 1;
}