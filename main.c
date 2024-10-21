#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

void turn_the_dice(int roll_no, Dice* d);
void reset_dice_hold(Dice* d);
void input_dice_hold(Dice* d);

int main()
{
    Dice main_dice;

    struct gamestate Game;
    int turns = 13;
    while ( Game.turn_number < turns )
    {
       int dice_roll = 0;
        while (dice_roll < 3)
        {
            turn_the_dice(dice_roll, &main_dice);
            printf("Hold 1: %d ", main_dice.hold[0]);
            dice_roll++;
        }
                    exit(0);
    }
}

void turn_the_dice(int roll_no, Dice* d)
{
    if (roll_no == 0) reset_dice_hold(d);

    input_dice_hold(d);
}

void reset_dice_hold(Dice* d)
{
    for (int i = 0; i < NUM_OF_DICE; i++) 
    {
        d->hold[i] = false;
    }
}

void input_dice_hold(Dice* d)
{
    bool hasHold;
    int input;
    for (int i = 0; i < NUM_OF_DICE; i++)
    {
        if (d->hold[i]) hasHold = true; 
    }
    if (!hasHold) printf("Do you want to hold any dice? --> ");
    else
    {
        printf("You currently hold \n");
        printf("Do you want to hold any more dice? --> ");
    }

    char line[11];
    char* endp;
    fgets(line, 10, stdin);

    for (int i = 0; line[i] != '\0';i++)
    {
        input = line[i] - 48;
        if (input > 0 && input < NUM_OF_DICE)
        {
        printf("Input %d ", input);
        d->hold[input-1] = true;
        }
    }

}