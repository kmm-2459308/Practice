//==========================================================
//	九九表(加算)を表示する
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()

int main()
{
	// ここをコーディングしてください。
	printf("   |  1   2   3   4   5   6   7   8   9\n");
	printf("---+--------------------------------------\n");
	for (int i = 1; i <= 9; i++)
	{	
		printf(" %d |", i);
		for (int j = 1; j <= 9; j++)
		{
			if(i+j<10)
				printf("  %d ",i+j);

			else
				printf(" %d ", i + j);
		}
		putchar('\n');
	}
	return 0;
}