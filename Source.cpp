#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int K;
	printf("Введите возраст: ");
	scanf_s ("%d", &K);

	if (K >= 5 && K <= 9)
		printf ("Мне %d лет", K);
	else if(K > 1 && K <= 4)
		printf("Мне %d года", K);
	else if(K == 1)
		printf("Мне %d год", K);
	else
		printf("Укажите возраст от 1 до 9 лет!");

	return 0;
}
