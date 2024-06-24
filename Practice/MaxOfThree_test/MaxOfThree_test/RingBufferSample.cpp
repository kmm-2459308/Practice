//=========================================================
//	�����O�o�b�t�@�T���v��
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // printf(),scanf()
#include <stdlib.h>  // srand(),rand();
#include <time.h>    // time()

// �֐��v���g�^�C�v
int getRandRange(int min, int max);

#define N 10

int main()
{
	srand(time(nullptr));
	int a[N];
	int cnt = 0;

	while (true) {
		int inputSize;
		do {
			printf("���͐�:");
			scanf("%d", &inputSize);
		} while (inputSize <= 0);
		for (int i = 0; i < inputSize; i++) {
			int num = getRandRange(0, 100);
			printf("�f�[�^:%d\n", num);
			a[cnt++ % N] = num;
		}

		int i = cnt - N;
		if (i < 0) {
			i = 0;
		}
		for (; i < cnt; i++) {
			printf("%2d�ڂ̐���:%d\n", i + 1, a[i % N]);
		}
		return 0;
	}
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}