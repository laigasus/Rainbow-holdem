#include <stdio.h>
#include "gameData.h"

void distribute(CARD *cardList)
{
    int distributeCount = 0;

    for (int j = 0; j < 4; j++)
    {
        printf("player[%d]: ", j + 1);
        for (int k = 0; k < 3; k++)
        {
            player[j].playerCard[k] = cardList[distributeCount++];
            printf("%-3d", player[j].playerCard[k].num);
        }
        printf("\n\n");
    }
    printf("dealer : ");
    for (int i = 0; i < 4; i++)
    {
        dealer.shareCard[i] = cardList[distributeCount++];
        printf("%-3d", dealer.shareCard[i].num);
    }
    puts("");

    printf("\ndistributed\n");
}

int whoFirst()
{
    int firstPos = 0;
    int min = player[0].playerCard[0].num;

    for (int i = 0; i < 4; i++)
    {
        if (player[i].playerCard[0].num < min)
        {
            firstPos = i;
            min = player[i].playerCard[0].num;
        }
    }
    printf("First User: player[%d]\n", firstPos + 1);
    return firstPos;
}