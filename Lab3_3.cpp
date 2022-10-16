#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 20
int main()
{
	srand(time(NULL));
	int a[n];
	int b[n];
	int res[n] = { 0 }, sign = 1, choice;
	printf("How to enter numbers:\n1)Random numbers\n2)From the keyboard\n");
	scanf_s("%d", &choice);
	if (choice != 1 && choice != 2)
	{
		printf("Wrong input!\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (choice == 1)
		{
			a[i] = rand() % 9 + 1;
			b[i] = rand() % 9 + 1;
		}
		if (choice == 2)
		{
			scanf_s("%d", &a[i]);
			scanf_s("%d", &b[i]);
		}
	}

	for (int k = 0; k < n; k++)
	{
		if (a[k] < b[k])
		{
			sign = -1;
			break;
		}
		else if (a[k] > b[k])
		{
			sign = 1;
			break;
		}
	}

	//Вывод первого числа
	for (int i = 0; i < n; i++)
		printf("%d", a[i]);

	printf(" - ");

	//Вывод второго числа
	for (int i = 0; i < n; i++)
		printf("%d", b[i]);

	printf(" = ");

	//Алгоритм подсчета
	if (sign == 1)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] - b[i] < 0)
			{
				a[i] += 10;
				a[i - 1]--;
			}
			res[i] = a[i] - b[i];
		}
	}
	else
	{
		printf("-");
		for (int i = n - 1; i >= 0; i--)
		{
			if (b[i] - a[i] < 0)
			{
				b[i] += 10;
				b[i - 1]--;
			}
			res[i] = b[i] - a[i];
		}
	}
	for (int j = 0; j < n; j++)
		printf("%d", res[j]);
}
