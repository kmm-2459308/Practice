//=========================================================
//	単純交換ソート 経過表示
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// 関数プロトタイプ
void BubbleSort(int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// 交換マクロ
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

int main()
{
	srand(time(nullptr));
	int arraySize;
	int* array;

	while (true) {
		do {
			printf("要素数:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr) {
			printf("calloc()失敗\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(1, 100);
		}
		dumpArray(array, arraySize);
		BubbleSort(array, arraySize);
		printf("昇順にソートしました\n");
		dumpArray(array, arraySize);

		free(array);
	}
	return 0;
}
//
// この関数を修正コーディングしてください。
// 比較回数と交換回数の変数は、適当なところに宣言してください。
// 
void BubbleSort(int array[], int arraySize)
{
	int c = 0;
	int s = 0;
	for (int i = 0; i < arraySize - 1; i++) 
	{
		printf("パス%d：\n",i+1);
		for (int j = arraySize - 1; j > i; j--) 
		{
			for (int l = 0; l < arraySize - 1; l++)
			{
				if (array[l]==array[j-1])
				{
					printf("+ ");
				}
				else
				{
					printf("  ");
				}
				if (array[l]>array[l+1])
				{
					printf("- ");
				}
				printf("%d ", array[l]);
			}putchar('\n');
			c++;
			if (array[j - 1] > array[j]) 
			{
				swap(int, array[j - 1], array[j]);
				s++;
			}
		}
	}
	printf("比較回数：%d\n",c);
	printf("交換回数：%d\n",s);
}

void dumpArray(const int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}