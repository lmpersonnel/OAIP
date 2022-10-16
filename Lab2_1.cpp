#include <stdio.h>
int main() {
	int S, a, b;
	printf("S is (S > 7!) ");
	scanf_s("%d", &S);
	if (S <= 7) printf("S must be more than 7!");
	for (b = 0; b < S; b++)
	{
		a = (S - (5 * b)) / 3;
		if (a >= 0 && b >= 0 && S == 3 * a + 5 * b)
		printf("A = %d, B = %d\n", a, b);
	}
		return 0;
}