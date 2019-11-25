#include "../headers/poker.h"

void print_card(Card* _card)
{
	if(_card->flipped == 0) {
		printf(
			BOLDGREEN
			"┏━━━━━┓\n"
			"┃ ◈ ◈ ┃\n"
			"┃ ◈ ◈ ┃\n"
			"┃ ◈ ◈ ┃\n"
			"┗━━━━━┛"RESET"\n"
		);
		return;
	}

	/************************************/
	int pips 	= _card->pips;
	char suit 	= _card->suit;
	char pips_printformat = 0;
	/************************************/
	char* color;
	char* shape;
	/************************************/
	switch (suit) {
		case 0: 
			color = BOLDRED;
			shape = HEART; 
			break;
		case 1:
			color = RED;
			shape = SPADE;
			break;
		case 2:
			color = BOLDBLUE;
			shape = CLUB;
			break;
		case 3:
			color = BLUE;
			shape = DIAMOND;
			break;
		default:
			break;
	}
	switch (pips) {
		case 2: pips_printformat = '2'; break;
		case 3: pips_printformat = '3'; break;
		case 4: pips_printformat = '4'; break;
		case 5: pips_printformat = '5'; break;
		case 6: pips_printformat = '6'; break;
		case 7: pips_printformat = '7'; break;
		case 8: pips_printformat = '8'; break;
		case 9: pips_printformat = '9'; break;
		case 10: pips_printformat = 'X'; break;
		case 11: pips_printformat = 'J'; break;
		case 12: pips_printformat = 'Q'; break;
		case 13: pips_printformat = 'K'; break;
		case 14: pips_printformat = 'A'; break;
		default: break;
	}
	/************************************/
	printf(
		"%s┏━━━━━┓\n"
		  "┃%s    ┃\n"
	 	  "┃  %c  ┃\n"
		  "┃    %s┃\n"
		  "┗━━━━━┛"RESET"\n",
		color,shape,pips_printformat,shape
	);
	return;
}

void print_deck(Deck* deck) {
	Card* cursor = deck->top;
	for(int i = 0; i < deck->size; i++){
		print_card(cursor);
		cursor = cursor->next;
	}
	return;
}

void print_score(Player* player, Card* card[5]){
	
	int score = 0, pair1 = 0, pair2 = 0;

	Card* cards[7];
	cards[0] = player->c1;
	cards[1] = player->c2;
	cards[2] = card[0];
	cards[3] = card[1];
	cards[4] = card[2];
	cards[5] = card[3];
	cards[6] = card[4];

	/* High card */
	score = 1;
	
	int count = 0, count2 = 0;
	for(int i = 0; i < 6; i++) {
		for(int j=i+1;j<7; j++) {
			if((cards[i]->pips == cards[j]->pips) && (pair1 == 0)) {
				/* One pair */ 	
				score = 2;
				pair1 = cards[i]->pips;
			} else if((cards[i]->pips == cards[j]->pips) && (pair1 > 0) && (cards[j]->pips != pair1)) {
				/* Two pair */
				score = 3;
				pair2 = cards[i]->pips;
			}
		}
		if(cards[i]->pips == pair1) count++;
		if(cards[i]->pips == pair2) count2++;
	}
	if(cards[6]->pips == pair1) count++;


	/* Three of a kind */
	if(count == 3 || count2 == 3) score = 4;
	
	/* Four of a kind */
	if(count == 4 || count2 == 4) score = 8;
	
	/* Straight */
	
	/* Flush */
	
	/* Full house */
	if(pair2 > 0 && count == 3) score = 7;

	/* Straight Flush */

	/* Royal Flush */

	printf("\n\t");
	switch(score) {
		case 1: printf("HIGH CARD\n"); break;
		case 2: printf("ONE PAIR\n"); break;
		case 3: printf("TWO PAIR\n"); break;
		case 4: printf("THREEE OF A KIND\n"); break;
		case 5: printf("STRAIGHT\n"); break;
		case 6: printf("FLUSH\n"); break;
		case 7: printf("FULL HOUSE\n"); break;
		case 8: printf("FOUR OF A KIND\n"); break;
		case 9: printf("STRAIGHT FLUSH\n"); break;
		case 10: printf("ROYAL FLUSH\n"); break;
		default: break;
	}
	printf("\n ==============================\n");
	return;
}


