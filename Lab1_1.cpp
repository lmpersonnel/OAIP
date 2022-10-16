#include<stdio.h>
int main()
{
	int r, l, h;
	float pi = 3.1415926, S1, S2, V;
		printf("Radius is ");
	scanf_s("%d", &r);
		printf("L is ");
	scanf_s("%d", &l);
		printf("H is ");
	scanf_s("%d", &h);
	if (r <= 0 || l <= 0 || h <= 0)
	{
		printf("Enter natural numbers!");
		return 0;
	}
	S1 = pi * r * l;
	S2 = pi * r * (r + l);
	V = pi * r * r * h / 3;
		printf("Side surfuce area is %.3f\n", S1);
		printf("Full area is %.3f\n", S2);
		printf("Volume is %.3f\n", V);
}