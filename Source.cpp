#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int K;
	printf("������� �������: ");
	scanf_s ("%d", &K);

	if (K >= 5 && K <= 9)
		printf ("��� %d ���", K);
	else if(K > 1 && K <= 4)
		printf("��� %d ����", K);
	else if(K == 1)
		printf("��� %d ���", K);
	else
		printf("������� ������� �� 1 �� 9 ���!");

	return 0;
}
