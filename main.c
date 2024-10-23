#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define NUM_OF_DICE 5
#define NUM_OF_CATEGORIES 15

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

const char categories[NUM_OF_CATEGORIES][20] = 
{
    "ONES",
    "TWOS",
    "THREES",
    "FOURS",
    "FIVES",
    "SIXES",
    "PAIRS",
    "DOUBLE_PAIR",
    "TRIPLES",
    "QUADRUPLETS",
    "SMALL_LADDER",
    "BIG_LADDER",
    "FULL_HOUSE",
    "CHANCE",
    "YAHTZEE"
};

typedef struct scorecard{
    int score[15];
    bool isFree[15];
}Scorecard;

typedef struct gamestate{
    int turn_number;
    Scorecard player;
}Gamestate;

void clear_input_buffer();
void initialize_game(Gamestate* g);
int roll_a_dice();
void turn_the_dice(int roll_no, Dice* d);
void reset_dice_hold(Dice* d);
void input_dice_hold(Dice* d);
void dice_hold_update(Dice* d, bool dest);
void score_round();
void print_valid_categories(Gamestate g);
void select_category(Gamestate* g, Dice d);
int calculate_score(Dice d, int category);

int main()
{
    Dice main_dice;

    Gamestate Game;
    int turns = 15;
    initialize_game(&Game);

    while ( Game.turn_number < turns )
    {
       int dice_roll = 0;
        while (dice_roll < 3)
        {
            turn_the_dice(dice_roll, &main_dice);
            // printf("Turn number %d, Roll number %d, Held dice: %d %d %d %d %d \n", Game.turn_number, dice_roll+1, main_dice.hold[0], main_dice.hold[1], main_dice.hold[2], main_dice.hold[3], main_dice.hold[4]);
            printf("Dice values: %d %d %d %d %d \n", main_dice.value[0], main_dice.value[1], main_dice.value[2], main_dice.value[3], main_dice.value[4]);
            dice_roll++;
        }
        print_valid_categories(Game);
        select_category(&Game, main_dice);
        // printf("1: %d 2: %d", Game.player.score[0], Game.player.score[1]);
        score_round();
    }
}

void clear_input_buffer()
{
    char c;
    while ((c=getchar()) != '\n' && c != EOF);
    
}

void initialize_game(Gamestate* g)
{
    for (int i = 0 ; i < NUM_OF_CATEGORIES ; i++)
    {
        g->player.score[i] = 0;
        g->player.isFree[i] = true;
    }
    g->turn_number = 0;
}

void turn_the_dice(int roll_no, Dice* d)
{
    if (roll_no == 0) reset_dice_hold(d);
    else input_dice_hold(d);

    for (int i = 0 ; i < NUM_OF_DICE ; i++)
    {
        if (!(d->hold[i])) d->value[i] = roll_a_dice();
    }
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
    // clear_input_buffer();
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

int roll_a_dice()
{
    return 6;   // this dice has been prepared
}

void score_round()
{

}

void print_valid_categories(Gamestate g)
{
    printf("Choose one of the following categories: \n");
    for (int i = 0 ; i < NUM_OF_CATEGORIES ; i++)
    {
        if (g.player.isFree[i]) printf("%i)%s ", i+1, categories[i]);
    }
}

void select_category(Gamestate* g, Dice d)
{
    bool valid_choice = false;
    int input = 0;
    while(!valid_choice)      
    {
        printf("--> ");
        scanf(" %d", &input);
        input--;
        clear_input_buffer();   // remove \n from stdin

        if (g->player.isFree[input])
        {
            g->player.score[input] = calculate_score(d, input);
            g->player.isFree[input] = false;
            g->turn_number++;
            valid_choice = true;
        } 
        else printf("Please choose a valid category\n");
    }   
}

int calculate_score(Dice d, int category)
{

    return 100;   // actual scoring added in later feature
}