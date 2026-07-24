#pragma once

typedef struct Player Player; //Lets deck.h know that this struct exists, so we don't need to include players.h and have circular dependencies
			      //this is called forward declaration

typedef struct {
    const char *rank;
    const char *suit;
} Card;

extern const char *ranks[];
extern const char *suits[];

void deal(Player *p1, Player *p2, Player *p3, Player *p4, Card deck[52]);
void shuffle(Card deck[52]);
void populate(Card deck[52], int card_count);

    




