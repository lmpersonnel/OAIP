#include <stdio.h>
int main()
{
	int n, S1 = 0, S2 = 0;
	printf("Enter a natural number: ");
	scanf_s("%d", &n);
	if (n <= 0)
	{
		printf("It must be a natural number\n");
		return 0;
	}
	for (int a = 0; a <= n; a += 2)
	{
		S1 += a * a;
		S2 += a * a * a;
	}
	printf("S1 is equal to %d\n", S1);
	printf("S2 is equal to %d\n", S2);
	
	return 0;
}