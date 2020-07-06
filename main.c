#include <stdio.h>
#include <stdbool.h>
#include "gameData.h"
#include "main.h"

int main()
{
    MakeCard(cardList);
    distribute(cardList);
    int firstUserPlay = whoFirst();
    play(firstUserPlay);
}