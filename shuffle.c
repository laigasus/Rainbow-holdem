#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define CARDMAX 55

typedef struct cards
{
    int num;
    char shape;
}CARD;

// 배열을 섞는 함수 
void shuffle(CARD *arr) 
{ 
    srand((unsigned int)time(NULL)); 
    CARD temp; int rn; 
    for (int i=0; i < CARDMAX-1; i++) 
    { 
        rn = rand() % (CARDMAX - i) + i;
        // i 부터 num-1 사이에 임의의 정수 생성 
        temp = arr[i]; 
        arr[i] = arr[rn]; 
        arr[rn] = temp; 
    } 
}

void MakeCard()
{
	CARD cardList[55];	//= {1x1, 2x2, ..., 9x9, 10x10};
	int numCount=1;
	int count=0; 
	do
	{
	    for(int j=0; j<numCount; j++)
	    {
	        cardList[count].num=numCount;
	        //printf("%2d", cardList[count].num);
	        count++;
	    }
	    numCount++;
		//printf("\n");
	}while(count<55);
	
	for(int i=0; i<55; i++) printf("%2d ", cardList[i].num);
	printf("\n");
	shuffle(cardList);
	for(int i=0; i<55; i++) printf("%2d ", cardList[i].num);
	
}