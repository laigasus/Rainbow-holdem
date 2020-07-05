/*
* 레인보우 홀덤-대탈출3 빵공장 숙소 편
* 0. 카드는 1x1, 2x2, ... , 10x10 으로 총 55장이다
* 1. 딜러는 공유카드를 4장, 플레이어는 개인카드를 3장 가지는 것으로 시작된다
* 2. 플레이어는 받은 카드중 가장 왼쪽에 배치된 카드를 공개한다
* 3. 공개된 카드중 가장 작은 숫자의 카드를 지닌 플레이어가 먼저,이후 시계방향으로 진행된다
* 4. 딜러의 첫번째 카드가 공개되면 배팅을 시작한다
* 5. 배팅의 종류
*     5.1. DIE(포기)      배팅권을 잃는다. 이전에 내건 토큰이 있으면 잃는다
*     5.2. CHECK(도전)    자신의 원하는 양만큼의 배팅을 한다
*     5.3. ALL-IN(승부)   자신이 가진 모든 토큰을 내건다
*      *배팅이 시작되면 DIE 아닌 이상 그보다 더 많이 배팅을 해야 한다
*     **이전 사람이 자신이 가진 양보다 많이 배팅한 경우 DIE 아니면 ALL-IN이 된다
*
* 6. 배팅 순서: 1번째 -> 2번째 -> ... -> n번째 -> 첫번
* 7. 공유카드 공개와 배팅이 반복되어 딜러의 카드가 모두 공개되면 최종 배팅을 진행
* 8. 이후 카드를 전체 공개한다
* 9. 플레이어의 점수는 (개인카드의 합+ 공유카드의 합)의 총합이며 점수가 가장 낮은 사람이 증리
* 10. 단. 개인과 공유중 같은 숫자의 카드는 모두 제거(3,4,..n개 같아도 제거)
* 11. 모든 숫자(개인카드와 공유카드)가 모두 다르면 그 사람은 무조건 승리 
*/

#include <stdio.h>
#include <stdbool.h>
#include "gameData.h"
#include "main.h"

void MakeCard(CARD *cardList);
void distribute(CARD *cardList);
int whoFirst();
void play(int firstUserPlay);

int main()
{
    MakeCard(cardList);
    distribute(cardList);
    int firstUserPlay = whoFirst();
    play(firstUserPlay);
}