#include "players.h"
#include <stdio.h>

void bet(Player *p, float *pot){
	if(p->archetype=='m'){
		float bet_amount;
    		printf("\nHow much would you like to bet?\n ");
    		scanf("%f", &bet_amount); 
		*pot += bet_amount;
		//the user is prompted to bet
		//the pot and users money is updated
	}
	else{
		p->money -= 1.0;
		printf("The player bet $1\n");
		*pot+= 1.0;
		//print how much they bet
		//update pot
	}

}


void take_turn(Player *p1, Player *p2, Player *p3, Player *p4, float *pot){
	//we still have to make this be in order according to who is the dealer
	Player *players[4] = {p1, p2, p3, p4};
	for (int i = 0; i<4;i++){
		bet(players[i], pot);
	}
	printf("\n");
}
