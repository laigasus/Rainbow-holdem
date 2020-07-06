/**참고 : 정수 배열에서 중복 값 (요소) 제거하기 (1) - O(n2) https://kkikkodev.tistory.com/55 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameData.h"

enum
{
    False,
    True
};

#define ARR_CAPACITY 7

void DeleteDuplicatedElementsInArr(int *arr, int *arrCapacity);
int SearchKeyInArr(int *arr, int arrCapacity, int key);
void PrintArr(int *arr, int arrCapacity);

int deletePos;

int deleteDuplicateValue(int *arr)
{
    int arrCapacity = ARR_CAPACITY;
    //	printf("\n중복 값 제거 전의 정수 배열\n");
    //	PrintArr(arr, arrCapacity);
    DeleteDuplicatedElementsInArr(arr, &arrCapacity);
    printf("\n중복 값 제거 후의 정수 배열\n");
    PrintArr(arr, arrCapacity);
    return arrCapacity;
}

void DeleteDuplicatedElementsInArr(int *arr, int *arrCapacity)
{
    int *uniqueArr = (int *)calloc(*arrCapacity, sizeof(int));
    int uniqueArrCount = 0;
    int i;
    for (i = 0; i < *arrCapacity; i++)
    {
        if (!SearchKeyInArr(uniqueArr, uniqueArrCount, arr[i]))
        {
            uniqueArr[uniqueArrCount++] = arr[i];
        }
        else
        {
            uniqueArr[deletePos] = 0;
        }
    }
    memset(arr, 0, sizeof(arr[0]) * (*arrCapacity));
    for (i = 0; i < uniqueArrCount; i++)
    {
        arr[i] = uniqueArr[i];
    }
    if (uniqueArr)
    {
        free(uniqueArr);
        uniqueArr = NULL;
    }
    *arrCapacity = uniqueArrCount;
}

int SearchKeyInArr(int *arr, int arrCapacity, int key)
{
    int i;
    for (i = 0; i < arrCapacity; i++)
    {
        if (arr[i] == key)
        {
            deletePos = i;
            return True;
        }
    }
    return False;
}

void PrintArr(int *arr, int arrCapacity)
{
    int i;
    for (i = 0; i < arrCapacity; i++)
    {
        if (arr[i] == 0)
            continue;
        printf("%-3d", arr[i]);
    }
    printf("\n");
}
