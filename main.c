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
void dice_hold_update(Dice* d, bool dest);
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
            printf("Roll number %d, Held dice: %d %d %d %d %d \n", dice_roll+1, main_dice.hold[0], main_dice.hold[1], main_dice.hold[2], main_dice.hold[3], main_dice.hold[4]);
            dice_roll++;
        }
                    exit(0);
    }
}

void turn_the_dice(int roll_no, Dice* d)
{
    if (roll_no == 0) reset_dice_hold(d);
    else input_dice_hold(d);
}

void reset_dice_hold(Dice* d)
{
    for (int i = 0; i < NUM_OF_DICE; i++) 
    {
        d->hold[i] = false;
    }
    printf("reset_dice_hold()\n");
}

void input_dice_hold(Dice* d)
{
    int held_dice = 0;
    for (int i = 0; i < NUM_OF_DICE; i++)
    {
        if (d->hold[i]) held_dice++; 
    }
    if (held_dice > 0)
    {
        printf("You currently hold dice ");
        for (int i = 0; i < NUM_OF_DICE ; i++) 
        {
            if (d->hold[i] == true) printf("%d ", i+1);
        }
        printf("\nEnter any dice you want roll again --> ");
        dice_hold_update(d, false);       
    } 
    printf("Enter any dice you want to hold --> ");
    dice_hold_update(d, true);
    

}

void dice_hold_update(Dice* d, bool dest)
{
    char line[11] = "";
    int input;
    char* endp;
    fgets(line, 10, stdin);

    for (int i = 0; line[i] != '\0';i++)
    {
        input = line[i] - 48;
        if (input > 0 && input < NUM_OF_DICE)
        {
        d->hold[input-1] = dest;
        }
    }
}