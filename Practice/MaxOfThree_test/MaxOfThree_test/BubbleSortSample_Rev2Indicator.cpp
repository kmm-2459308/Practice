//=========================================================
//	�P�������\�[�g ��Q�� �o�ߕ\��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
void BubbleSort(int array[], int arraySize);
void indicate(int i, int j, bool isSwap, int array[], int arraySize);
int getRandRange(int min, int max);
void dumpArray(const int array[], int arraySize);
// �����}�N��
#define swap(type,a,b)	do{type tmp=a; a=b; b=tmp;}while(false)

int c = 0;
int s = 0;

int main()
{
	srand(time(nullptr));
	int arraySize;
	int* array;

	while (true) {
		do {
			printf("�v�f��:");
			scanf("%d", &arraySize);
		} while (arraySize <= 2);

		array = (int*)calloc(arraySize, sizeof(int));
		if (array == nullptr) {
			printf("calloc()���s\n");
			exit(1);
		}
		for (int i = 0; i < arraySize; i++) {
			array[i] = getRandRange(1, 100);
		}
		dumpArray(array, arraySize);
		c = 0;
		s = 0;
		BubbleSort(array, arraySize);
		printf("�����Ƀ\�[�g���܂���\n");
		dumpArray(array, arraySize);
		printf("��r��:%d\n", c);
		printf("������:%d\n", s);

		free(array);
	}
	return 0;
}
//
// ���̊֐����C���R�[�f�B���O���Ă��������B
// ��r�񐔂ƌ����񐔂̕ϐ��́A�K���ȂƂ���ɐ錾���Ă��������B
// 
void BubbleSort(int array[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++) {
		printf("�p�X%d:\n", i+1);
		for (int j = arraySize - 1; j > i; j--) {
			bool isSwap = array[j - 1] > array[j];
			c++;
			indicate(i, j, isSwap, array, arraySize);
			if (array[j - 1] > array[j]) {
				swap(int, array[j - 1], array[j]);
				s++;
			}
		}
	}
}

void indicate(int i, int j, bool isSwap, int array[], int arraySize)
{
	if (j == arraySize - 1)
	{
		printf("�p�X %d:\n", i + 1);
	}
	for (int k = 0; k < arraySize; k++)
	{ int mark = ' ';
	if (k == j - 1) 
		{
			mark = isSwap ? '+' : '-'; 
		}printf("%3d %c", array[k], mark);
	}putchar('\n');
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