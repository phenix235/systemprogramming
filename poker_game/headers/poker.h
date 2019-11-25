#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/* [ Chapter 9: Structures and Unions ]  
 *
 *	Define "typedef struct" of card, deck, and player 
 *	and Appropriate "Data Structure" (just one of stack, queue, linked list)
 *
 *  Card has 
 *	1) integer of pips 
 *	2) character of suit 
 *	3) bool of flipped or not  (type _Bool)
 * 	4) pointer which points next card
 *
 *  Deck has
 * 	1) pointer of top card
 * 	2) size indicates how many cards are inside the deck
 * 	
 *  Player has
 *	1) string name
 *	2) pointer of card one
 *	3) pointer of card two
 *	3) int account
 */

/* typedef structs to define */


	/* Define typedef here */


/* function to complete -----> work in ../sources/poker_comp.c */
Card* newcard(int,char);
Deck* newdeck();
Player* newplayer(char*,int);
Card* eject(Deck*);

/* given functions */
void shuffle(Deck*);

/* print functions */
void print_card(Card*);
void print_deck(Deck*);

/* Calculation of scores */
void print_score(Player*, Card*[5]);

