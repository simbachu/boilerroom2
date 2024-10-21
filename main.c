#include <stdio.h>
#include <stdbool.h>

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

void turn_the_dice();

int main()
{
    // Dice data structure
    int dice[5] = {1, 1, 1, 1, 1};
    struct gamestate Game;
    int turns = 13;
    while ( Game.turn_number < turns )
    {

        int dice_rolls = 0;
        while (dice_rolls < 3)
        {
            turn_the_dice();
            dice_rolls++;
        }

    }
}