#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<locale.h>

int powerTen(int a)
{
    int num = 10;
    for (int i = 1; i < a; i++)
        num *= 10;
    return num;
}

int main()
{
    srand(time(NULL));
    int choice;
    float rd, ten;
    printf("How to enter numbers:\n1)Random numbers\n2)From the keyboard\n");
    
    while (scanf_s("%d", &choice) != 1 || choice != 1 && choice != 2 || getchar() != '\n')
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }

    float array[100];
    int amount;
    printf("Enter amount: ");
    while (scanf_s("%d", &amount) != 1 || amount > 100 || amount <= 0 || getchar() != '\n')
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }
    for (int i = 0; i < amount; i++)
    {
        if (choice == 1)
        {
            rd = rand() % 100001;
            ten = powerTen(rand() % 7);
            int min = rand() % 2;
            if (min == 0)
                min = -1;
            else
                min = 1;
            array[i] = rd / ten * min;
        }
        else
        {
            printf("%d) ", i + 1);
            scanf_s("%f", &array[i]);
        }
    }
    if (choice == 1)
    {
        printf("  ");
        for (int i = 0, j = 1; i < amount; i++, j++)
        {
            printf("%f  ", array[i]);
            if (j == 7)
                printf("\n  ");
        }
    }

    int min = 0;
    array[min] = array[0];
    for (int i = 0; i < amount; i++)
    {
        if (array[min] > array[i])
        {
            array[min] = array[i];
            min = i;
        }
    }
    printf("\n\nIndex min: %d\n", min);

    int fst = -1, scn = -1;

    for (int i = 0; i < amount; i++)
    {
        if (array[i] < 0)
        {
            fst = i;
            break;
        }
    }

    for (int j = fst + 1; j < amount; j++)
    {
        if (array[j] < 0)
        {
            scn = j;
            break;
        }
    }

    if (scn - fst == 1 || fst == -1 || scn == -1)
    {
        printf("\n\nTry again");
        return 0;
    }

    float sum = 0;
    for (int i = fst + 1; i < scn; i++)
    {
        sum += array[i];
    }
    printf("\nSum is %f\n", sum);
}