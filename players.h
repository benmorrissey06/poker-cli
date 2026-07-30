#include "deck.h"
#pragma once

typedef struct Player {
	float money;
	char archetype;
	Card card1;
	Card card2;
	float current_bet;
	char blind_status;
	}Player;

void take_turn(Player *p1, Player *p2, Player *p3, Player *p4, float *pot);

void bet(Player *p, float *pot);

//Player player1;

//Player player2;

//Player player3;





