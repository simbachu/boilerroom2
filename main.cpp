#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
// #include <stdlib.h>
// #include <stdbool.h>
#include <time.h>

#define NUM_OF_DICE 5
#define NUM_OF_CATEGORIES 15


// struct Gamestate{
//     int turn_number;
//     std::vector<Scorecard> player;
// };


void clear_input_buffer();
// int roll_a_dice();
// void turn_the_dice(int roll_no, std::vector<Dice> &d);
// void reset_dice_hold(Dice* d);
// void input_dice_hold(Dice* d);
// void dice_hold_update(Dice* d, bool dest);
// void score_round();
// void print_valid_categories(Gamestate g);
// void initialize_game(Gamestate* g);
// void select_category(Gamestate* g, Dice d);
// int calculate_score(Dice d, int category);



enum Category {
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    ONE_PAIR,
    TWO_PAIRS,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    SMALL_STRAIGHT,
    LARGE_STRAIGHT,
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
    "ONE_PAIR",
    "TWO_PAIRS",
    "THREE_OF_A_KIND",
    "FOUR_OF_A_KIND",
    "SMALL_STRAIGHT",
    "LARGE_STRAIGHT",
    "FULL_HOUSE",
    "CHANCE",
    "YAHTZEE"
};


struct Dice
{
    bool hold;
    int value;
};

class Scorecard
{
    public:
    std::vector<int> score;
    std::vector<bool> hasValue;

    public:
    Scorecard() : score(NUM_OF_CATEGORIES), hasValue(NUM_OF_CATEGORIES, false) { }
  
};

class Player{
    public:
    int player_index{};
    std::string name{};
    Scorecard scorecard{};
};





int main()
{
    std::vector<Dice> main_dice(5);
    Player player1;
    // player1.player_index = 0;
    // player1.score_categories.score[0] = 15;
    std::cout << "Player 1 ONES has value: " << player1.scorecard.hasValue[ONES] << "\n";
    std::cout << "Player 1 index: " << player1.player_index << "\n";

    // Gamestate Game;
    const int turns = NUM_OF_CATEGORIES;
    int current_turn = 0;
    // initialize_game(&Game);

    // while ( Game.turn_number < turns )
    // {
    //    int dice_roll = 0;
    //     while (dice_roll < 3)
    //     {
    //         turn_the_dice(dice_roll, main_dice);
    //         std::cout << main_dice[0].value << " " 
    //                   << main_dice[1].value << " " 
    //                   << main_dice[2].value << " " 
    //                   << main_dice[3].value << " " 
    //                   << main_dice[4].value << "\n";
    //         dice_roll++;
    //     }
    //     print_valid_categories(Game);
    //     select_category(&Game, main_dice);
    //     score_round();
    // }

    return 0;
}

void clear_input_buffer()
{
    char c;
    while ((c=getchar()) != '\n' && c != EOF);
    
}

// void initialize_game(Gamestate* g)
// {
//     for (int i = 0 ; i < NUM_OF_CATEGORIES ; i++)
//     {
//         g->player.score[i] = 0;
//         g->player.hasValue[i] = false;
//     }
//     g->turn_number = 0;
// }

// void turn_the_dice(int roll_no, std::vector<Dice> &d)
// {
//     if (roll_no == 0) reset_dice_hold(d);
//     else input_dice_hold(d);

//     for (int i = 0 ; i < NUM_OF_DICE ; i++)
//     {
//         if (!(d[i].hold)) d[i].value = roll_a_dice();
//     }
// }

// void reset_dice_hold(Dice* d)
// {
//     for (int i = 0; i < NUM_OF_DICE; i++) 
//     {
//         d->hold[i] = false;
//     }
// }

// void input_dice_hold(Dice* d)
// {
//     int held_dice = 0;
//     for (int i = 0; i < NUM_OF_DICE; i++)
//     {
//         if (d->hold[i]) held_dice++; 
//     }
//     if (held_dice > 0)
//     {
//         printf("You currently hold dice ");
//         for (int i = 0; i < NUM_OF_DICE ; i++) 
//         {
//             if (d->hold[i] == true) printf("%d ", i+1);
//         }
//         printf("\nEnter any dice you want roll again --> ");
//         dice_hold_update(d, false);       
//     } 
//     printf("Enter any dice you want to hold --> ");
//     dice_hold_update(d, true);    
// }

// void dice_hold_update(Dice* d, bool dest)
// {
//     // clear_input_buffer();
//     char line[11] = "";
//     int input;
//     char* endp;
//     fgets(line, 10, stdin);

//     for (int i = 0; line[i] != '\0';i++)
//     {
//         input = line[i] - 48;
//         if (input > 0 && input < NUM_OF_DICE)
//         {
//         d->hold[input-1] = dest;
//         }
//     }
// }

// int roll_a_dice()
// {
//     return (rand() % 6) + 1;
// }

// void score_round()
// {

// }

// void print_valid_categories(Gamestate g)
// {
//     std::cout << "Choose one of the following categories: \n";
//     // printf("Choose one of the following categories: \n");
//     for (int i = 0 ; i < NUM_OF_CATEGORIES ; i++)
//     {
//         if (!g.player.hasValue[i]) std::cout << i+1 << ")" << categories[i] << " ";
//         // printf("%i)%s ", i+1, categories[i]);
//     }
// }

// void select_category(Gamestate* g, Dice d)
// {
//     bool valid_choice = false;
//     int input = 0;
//     while(!valid_choice)      
//     {
//         std::cout << "--> ";
//         // printf("--> ");
//         std::cin >> input;
//         // scanf(" %d", &input);
//         input--;
//         // clear_input_buffer for c, not needed for c++ ?
//         // clear_input_buffer();   // remove \n from stdin

//         if (!(g->player.hasValue[input]))
//         {
//             g->player.score[input] = calculate_score(d, input);
//             g->player.hasValue[input] = true;
//             g->turn_number++;
//             valid_choice = true;
//         } 
//         else 
//         {
//             std::cout << "Please choose a valid category\n";
//             // printf("Please choose a valid category\n");
//         }
//     }   
// }

// int calculate_score(Dice d, int category)
// {
//     return 100;   // actual scoring added in later feature
// }