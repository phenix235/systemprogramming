#include "../headers/poker.h"

int main(int argc, char** argv)
{
	/* 포커게임을 시작하기 위한 카드 덱을 생성한다. */
	Deck* deck = newdeck();
	
	char enter;

	/* 카드 덱을 섞는다. */
	for(int i=0; i < 100; i++) shuffle(deck);

	/* 플레이어를 생성하고 플레이어에게 카드 2장을 준다. */
	Player* player = newplayer("john",10000);
	player->c1 = eject(deck);
	player->c2 = eject(deck);

	
	/* 뒤집어져 있던 카드 두 장을 뒤집어서 본인이 본다. */
	printf("\n ======== 받으신 카드 2장을 확인합니다. ========\n");
	enter = getchar();
	player->c1->flipped = 1;
	print_card(player->c1);
	player->c2->flipped = 1;
	print_card(player->c2);

	/* 딜러가 덱 카드 3장을 확인시켜준다. */
	printf("\n ====== 딜러가 카드 3장을 확인시켜줍니다. ======\n");
	enter = getchar();
	Card* card[5];
	card[0] = eject(deck);
	card[1] = eject(deck);
	card[2] = eject(deck);
	card[3] = eject(deck);
	card[4] = eject(deck);
	
	card[0]->flipped = 1;	
	card[1]->flipped = 1;	
	card[2]->flipped = 1;	

	print_card(card[0]);
	print_card(card[1]);
	print_card(card[2]);

	/* 다음 카드를 보여준다. */
	printf("\n ====== 딜러가 카드 1장을 추가로 확인시켜줍니다. ======\n");
	enter = getchar();
	card[3]->flipped = 1;
	print_card(card[3]);

	/* 마지막 카드를 보여준다. */
	printf("\n ====== 딜러가 마지막 카드를 확인시켜줍니다. ======\n");
	enter = getchar();
	card[4]->flipped = 1;
	print_card(card[4]);

	/* 총 점수를 보여준다. */
	printf("\n ====== 총 점수를 보여줍니다.  ======\n");
	enter = getchar();
	print_score(player, card);

	
	

	return 0;
}
