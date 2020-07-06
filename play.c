#include <stdio.h>
#include <ctype.h>
#include "gameData.h"
#include <unistd.h>

int deleteDuplicateValue(int *arr);
void result();

void chargeCoin()
{
    for (int i = 0; i < 4; i++)
        player[i].coin = TokenMax;
}

int totalCoin = 0;
int turn;

void status(int round)
{
    int l = 1;

    dealer.shareCard[round - 1].masked = false;
    printf("dealer : ");
    for (int i = 0; i < 4; i++)
    {
        if (dealer.shareCard[i].masked)
            printf("?  ");
        else
            printf("%-3d", dealer.shareCard[i].num);
    }
    printf("\t\tBet: \033[0;33m%d\033[0m\t\tRound: %d", totalCoin, round);
    puts("");
    for (int i = 0; i++ < 50;)
        printf("-");
    puts("");

    for (int j = 0; j < 4; j++)
    {
        {
            if (j == turn)
            {
                printf("\033[36m");
            }
            if (j == 0)
            {
                printf("    me: ");
            }
            else
            {
                printf("com[%d]: ", j + 1);
            }

            printf("\033[0m");
        }

        for (int k = 0; k < 3; k++)
        {
            printf("%-3d", player[j].playerCard[k].num);
        }
        printf("\t\033[0;33m%d\033[0m", player[j].coin);
        if (l == 2)
        {
            printf("\n\n");
            l = 0;
        }
        else
            printf("\t\t");
        l++;
    }
}

void play(firstUserPlay)
{

    chargeCoin();
    turn = firstUserPlay;
    int round = 1;
    while (round < 5)
    {
        for (int i = 0; i < 4; i++)
        {
            system("clear");
            if (turn % 4 == 0)
                turn = 0;
            status(round);

            //딜러의 공유카드가 순차적으로 개봉(코드 구현 필요)
            //DIE 한 플레이어는 다음 게임 전까지 참가 못함.
            //플레이어 로테이션은 두명이 남기 전까지
            //플레이어는 그 공유카드를 보고 배팅 시작
            if (player[turn].condition == 'o' || player[turn].condition == 'a')
            {
                goto DIEorALL;
            }

            int choose;
            int inputValue;
            int betCoin;

        InputAgain:
            printf("choose(1. DIE\t2. CHECK\t3. ALL-IN)\t>");

            scanf("%d", &choose);

            switch (choose)
            {
            case 1:
                printf("DIE. challenge next game...\n"); //sleep(2);
                player[turn].condition = 'o';
                break;

            case 2:
                printf("CHECK. How many? =>");
                do
                {
                    scanf("%d", &inputValue);

                } while (!(inputValue % 1 == 0));

                betCoin = inputValue;
                totalCoin += betCoin;
                player[turn].coin -= betCoin;
                printf("you bet %d...\n", betCoin); //sleep(2);
                break;

            case 3:
                betCoin = player[turn].coin;
                totalCoin += betCoin;
                player[turn].coin -= betCoin;
                printf("!ALL-IN!...\n"); //sleep(2);
                player[turn].condition = 'a';
                break;

            default:
                printf("you input Wrong number!\n");
                sleep(1);
                system("clear");

                status(round);
                goto InputAgain;
            }
        DIEorALL:
            turn++;
        }
        round++;
    }
    result();
}

void result()
{
    int totalScore = 0;
    int playerCardList[7];
    int arrLength;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            playerCardList[j] = player[i].playerCard[j].num;
        }
        for (int j = 3; j < 7; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                playerCardList[j] = dealer.shareCard[j].num;
            }
        }
        arrLength = deleteDuplicateValue(playerCardList);

        if (arrLength == 7)
            player[i].isRAINBOW = true;
        for (int j = 0; j < arrLength; j++)
            player[i].sumCard += playerCardList[j];
    }

    int min = player[0].sumCard;

    int winnerPos;
    for (int i = 0; i < 4; i++)
    {
        if (player[i].isRAINBOW == true)
        {
            winnerPos = i;
            break;
        }

        if (player[i].sumCard < min)
        {
            winnerPos = i;
            min = player[i].sumCard;
        }
        printf("\nplayer[%d]: %d\n\n", i + 1, player[i].sumCard);
    }
    player[winnerPos].coin += totalCoin;
    printf("\nplayer[%d] WIN!!!!!!!!!!!!!!!\n", winnerPos + 1);
}
