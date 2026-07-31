#include "players.h"
#include <stdio.h>


float bet(Player *p, float *pot, float highest_bet) {
    if (p->is_folded == 1) {
        return highest_bet; 
    }

    if (p->archetype == 'm') {
        float bet_amount;
        printf("Current highest bet is $%.2f\n", highest_bet);
        printf("How much would you like to bet? ");
        scanf("%f", &bet_amount); 
        printf("\n");
        
        if (bet_amount > p->money) {
            printf("You don't have enough money! You fold.\n");
            p->is_folded = 1; 
        } 
        else {
            p->money -= bet_amount;
            *pot += bet_amount;
            
            if (bet_amount > highest_bet) {
                highest_bet = bet_amount;
            }
        }
        
        printf("Your total money is $%.2f\n", p->money);
    } 
    else {
        float bot_bet;
        
        if (highest_bet == 0.0f && p->money >= 1.0f) {
            bot_bet = 1.0f;
        } else {
            bot_bet = highest_bet; 
        }
        
        if (bot_bet > p->money) {
            printf("The bot doesn't have enough money and folds.\n");
            p->is_folded = 1; 
        } 
        else {
            if (bot_bet == 0.0f) {
                printf("The bot checks.\n");
            } else if (bot_bet == 1.0f && highest_bet == 0.0f) {
                printf("The bot bets $1.00\n");
            } else {
                printf("The bot calls the bet of $%.2f\n", bot_bet);
            }
            
            p->money -= bot_bet;
            *pot += bot_bet;
            
            if (bot_bet > highest_bet) {
                highest_bet = bot_bet;
            }
        }
    }

    printf("The overall pot is $%.2f\n\n", *pot);
    
    return highest_bet; 
}
        

void take_turn(Player *p1, Player *p2, Player *p3, Player *p4, float *pot){
    //we still have to make this be in order according to who is the dealer
    float highest_bet = 0.0f;
    Player *players[4] = {p1, p2, p3, p4};
    for (int i = 0; i<4;i++){
        highest_bet = bet(players[i], pot, highest_bet);
    }
    printf("\n");
}

void showdown(Player *p1, Player *p2, Player *p3, Player *p4, float *pot) {
    printf("\n--- SHOWDOWN ---\n");
    
    Player *players[4] = {p1, p2, p3, p4};
    
    for (int i = 0; i < 4; i++) {
        if (players[i]->is_folded == 1) {
            printf("Player %d: Folded\n", i + 1);
        } else {
            printf("Player %d: %s of %s AND %s of %s\n", 
                   i + 1, 
                   players[i]->card1.rank, players[i]->card1.suit, 
                   players[i]->card2.rank, players[i]->card2.suit);
        }
    }
    
    int winner;
    printf("\nWho won the hand? (1, 2, 3, or 4): ");
    scanf("%d", &winner);
    
    if (winner >= 1 && winner <= 4) {
        players[winner - 1]->money += *pot;
        printf("\nPlayer %d wins the pot of $%.2f!\n", winner, *pot);
        printf("Player %d now has $%.2f total.\n", winner, players[winner - 1]->money);
    } else {
        printf("\nInvalid input. No one gets the pot.\n");
    }
    
    *pot = 0.0f; 
}
