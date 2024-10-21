#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int random_int();

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

void take_turn();

int main(){
    // Dice data structure
    int dice[5] = {1, 1, 1, 1, 1};
    struct gamestate Game;
    int turns = 13;
    while ( Game.turn_number < turns ){
        take_turn();
    }
}


int random_int()
{
    srand(time(NULL));
    int rndm = rand() % (6 + 1);
    return rndm;
}