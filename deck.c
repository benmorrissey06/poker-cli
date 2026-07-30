#include "deck.h"
#include "players.h"
#include <stdio.h>
#include <stdlib.h>


const char *ranks[] = {
        "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
    };
const char *suits[] = {
        "Clubs", "Diamonds", "Hearts", "Spades"
    };


void deal(Player *p1, Player *p2, Player *p3, Player *p4, Card deck[52]){ //function to deal up them cards
	//This does not yet take into account potential dealer rotation, which will be determined by status
	//
	//
	//Use pointers to pass everything in, and to modify the cards, but we didnt use pointers to define those cards so that they remain there until we are certain we want to clear them for next hand.
	p1-> card1 = deck[0];
	p2-> card1 = deck[1];
	p3-> card1 = deck[2];
	p4-> card1 = deck[3];
	p1-> card2 = deck[4];
	p2-> card2 = deck[5];
	p3-> card2 = deck[6];
	p4-> card2 = deck[7];
	}

void shuffle(Card deck[52]){
    for (int i = 51; i > 0; i--) {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
        
        // Swap deck[i] with deck[j]
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void populate(Card deck[52], int card_count){
for (int s = 0; s < 4; s++) {//populate deck
        	for (int r = 0; r < 13; r++) {
            		deck[card_count].rank = ranks[r];
            		deck[card_count].suit = suits[s];
            		card_count++;
        	}
    }
}

void flop(Card deck[52]){
	printf("Here's the flop!");
	//burn one
	printf("%s of %s\n",deck[9].rank,deck[9].suit);
	printf("%s of %s\n",deck[10].rank,deck[10].suit);
	printf("%s of %sn",deck[11].rank,deck[11].suit);
}

void turn(Card deck[52]){
	printf("Here's the turn!");
	//burn one
	printf("%s of %s\n",deck[13].rank,deck[13].suit);
}

void river(Card deck[52]){
	printf("Here's the river!");
	//burn one
	printf("%s of %s\n",deck[15].rank,deck[15].suit);
}
