//Todo
//finish the commented out functions
//allocate the right functions to the right files for better readability

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "deck.h"
#include "players.h"

//void flop(Player *p1, Player *p2, Player *p3, Player *p4, Card *deck[52]) FLOP FIRST 3
//FLOP NEXT 1
//FLOP NEXT 1
//

/*
void take_turn(){
	for(int i=0;i<4; i++){
		if(i=0){
			bet(player1)

int bet(){
	if player == player1{
		//bet according to player 1s archetype and hand
		//etc
*/


int main() {
    

    float pot;
    char letter;
    srand(time(NULL));

    printf("Ready to play? (Y/n): ");
    scanf("%c", &letter); 

    //Starting with 4 players here

    Player player1 = {.archetype = 'm',.money=20.0};//we are player 1 btw
    Player player2 = {.money = 20.0};
    Player player3 = {.money = 20.0};
    Player player4 = {.money = 20.0};

    Card deck[52]; //make deck of 52 cards
    int card_count = 0;

    populate(deck,card_count);    
    shuffle(deck);    
    deal(&player1, &player2, &player3, &player4, deck);
        //dont need to write it as pointer here, since it already is when initiated as array
	    //
	    //We pass in pointers for better speed, and since we are going to modify these values, it is the best way to do it for permenent modification. otherwise nonpointers would modify local values


    if (letter == 'Y'){
    	
	
	//Initialization; Condition; Update
	//printf("You're cards are: \n");
	printf("Shuffling...\n");
	for(int i=0;i<3;i++){
		printf("#");
		fflush(stdout);
		usleep(200000);
		}
	printf("\n");
	sleep(1);
	printf("%s of %s\n", player1.card1.rank, player1.card1.suit);
   	sleep(1);
    	printf("%s of %s\n", player1.card2.rank, player1.card2.suit);
	//printf("---\n");
	
        take_turn(&player1, &player2, &player3, &player4, &pot);
        flop(deck);
	
        take_turn(&player1, &player2, &player3, &player4, &pot);
        turn(deck);
        take_turn(&player1, &player2, &player3, &player4, &pot); 
        river(deck);
        take_turn(&player1, &player2, &player3, &player4, &pot);
    
    	return 0; 

    }
   
}

