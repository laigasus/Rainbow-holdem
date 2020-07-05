#include <stdio.h>
#include <ctype.h>
#include "gameData.h"

void chargeCoin()
{
    for (int i = 0; i < 4; i++)
        player[i].coin = TokenMax;
}
void play(firstUserPlay)
{
    chargeCoin();
    int turn = firstUserPlay;
    for (int i = 0; i < 4; i++)
    {
        if (turn % 4 == 0)
            turn = 0;
        printf("차례: player[%d]\n", turn + 1);
        //딜러의 공유카드가 순차적으로 개봉(코드 구현 필요)
        //플레이어는 그 공유카드를 보고 배팅 시작
        printf("choose(1. DIE\t2. CHECK\t3. ALL-IN)\t\033[1;33mCOIN: %d\033[0m ", player[turn].coin);
        int choose;
        int inputValue;
        int betCoin;
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("DIE. your turn is end\n");
            break;

        case 2:
            printf("CHECK. How many? =>");
            do
            {
                scanf("%d", &inputValue);

            } while (!(inputValue % 1 == 0));

            betCoin = inputValue;
            player[turn].coin -= betCoin;
            printf("you bet %d. left: %d\n", betCoin, player[turn].coin);
            break;

        case 3:
            betCoin = player[turn].coin;
            player[turn].coin -= betCoin;
            printf("!ALL-IN! left: %d", player[turn].coin);
        }
        turn++;
    }
}
