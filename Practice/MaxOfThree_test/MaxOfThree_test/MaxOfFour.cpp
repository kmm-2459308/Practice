//==============================================
//  4�l�̍ő�l
//==============================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
// �֐��v���g�^�C�v
int MaxOfFour(int a, int b, int c, int d);

int main()
{
	srand(time(nullptr));
	int a = rand() % 100;
	int b = rand() % 100;
	int c = rand() % 100;
	int d = rand() % 100;
	int ans = MaxOfFour(a, b, c, d);
	printf("MaxOfFour(%d,%d,%d,%d) => %d\n", a, b, c, d, ans);
	return 0;
}
int MaxOfFour(int a, int b, int c, int d)
{
	// �������R�[�f�B���O���Ă��������B
	int max4 = a;
	max4 > b ? max4 : max4 = b;
	max4 > c ? max4 : max4 = c;
	max4 > d ? max4 : max4 = d;
	return max4;
}