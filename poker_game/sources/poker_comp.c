#include "../headers/poker.h"

/* [ Chapter 9: Structures and Unions ]  
 *
 *  Functions to create
 *  
 *	1) newcard(-,-): Use malloc
 *
 *	2) newdeck(): Use malloc 
 *	
 * 	3) newplayer(): Use malloc
 *
 *  	4) eject(): only can pop out from the top of the Deck 
 *		    (pop from the bottom is not allowed) 
 *
 *	5) shuffle(-): use srand/rand
 */

/* function to complete */
Card* newcard(int _pips,char _suit){
	
	/* write codes */	

	return card;	
}
	
Deck* newdeck(){
	
	/* write codes */	

	Card* cursor;	
	for(char s = 0; s <= 3; s++) {
		for(int p = 2; p <= 14; p++) {
			if(deck->top == NULL) { 
				deck->top = newcard(p,s);
				cursor = deck->top;
			} else {
				cursor->next = newcard(p,s);
				cursor = cursor->next;
			} deck->size++;
		}
	}
	return deck;
}

Player* newplayer(char* _name,int _account){
	
	/* write codes */	
	
	return player;
}

Card* eject(Deck* deck) {
	Card* temp;

	/* write codes */	

	return temp;
}

void shuffle(Deck* deck){
	Deck* head = (Deck*)malloc(sizeof(Deck));	/* 분리하는 섞음 카드 뭉치를 임시 저장하는 공간이다. */
	Deck* mid = (Deck*)malloc(sizeof(Deck));
	Deck* tail = (Deck*)malloc(sizeof(Deck));

	srand(clock()); 	/* time(NULL) 보다 훨씬 빠른 주기로 시드를 변경한다. 프로그램이 실행된 이후 얼만큼의 cpu clock tick이 경과했는지 측정한다. */
	
	if(deck->size<=20) printf("\n\nERROR: deck size should be bigger than 20\n\n");
	unsigned char index = rand()%(deck->size-20)+10;
	unsigned char endex = rand()%(deck->size - index-1)+1;
	
	Card *cindex, *cendex, *aendex, *bendex;
	cendex = deck->top;
	for(int i = 0; i < index-1; i++) {
		cendex = cendex->next;
	}
	/* 헤드 덱이 생성된다. */
	head->top = deck->top;
	head->size = index-1;
	cindex = cendex->next;
	cendex->next = NULL;
	aendex = cendex;
	cendex = cindex;
	
	for(int i = 0; i < endex-1; i++) {
		cendex = cendex->next;
	}

	/* 미드 덱이 생성된다. */
	mid->top = cindex;
	mid->size = endex-1;
	cindex = cendex->next;
	cendex->next = NULL;
	bendex = cendex;
	cendex = cindex;

	for(int i =0; i < (deck->size - index - endex-1); i++) {
		cendex = cendex->next;
	}
	cendex->next = NULL;
	
	/* 테일 덱이 생성된다. */
	tail->top = cindex;
	tail->size = (deck->size - index - endex);	
	
	deck->top = mid->top;
	aendex->next = tail->top;
	bendex->next = head->top;

	free(head); free(mid); free(tail); 		
	return;
}

void freedeck(Deck* deck){  	/* malloc을 해줬던 메모리 영역들에 대하여 free()를 하지 않으면 메모리 문제가 발생하여 런타임 에러가 날 수 있다. */

	/* write codes */	

	return;
}
