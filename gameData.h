#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define TokenMax 10
#define CARDMAX 55

typedef struct cards
{
    int num;
    char shape;
    bool masked;
} CARD;

typedef struct player_info
{
    CARD playerCard[3];
    bool isRAINBOW;
    int coin;
} USER;

typedef struct dealer_info
{
    CARD shareCard[4];
} DEALER;

CARD cardList[55]; //= {1x1, 2x2, ..., 9x9, 10x10};

DEALER dealer;
USER player[4];