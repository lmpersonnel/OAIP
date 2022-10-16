#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int main()
{
    srand(time(NULL));
    int choice;
    int rd;
    printf("How to enter numbers:\n1)Random numbers\n2)From the keyboard\n");
    scanf_s("%d", &choice);
    if (choice != 1 && choice != 2)
    {
        printf("Wrong input!\n");
        return 0;
    }

    int array[100];
    int amount;
    printf("Enter amount: ");
    if (scanf_s("%d", &amount) != 1 || amount > 100 || amount <= 0)
    {
        printf("Wrong input!\n");
        return 0;
    }
    for (int i = 0; i < amount; i++)
    {
        if (choice == 1)
        {
            rd = rand() % 1001;
            int mn = rand() / 3 % 2;
            if (mn == 0)
                mn = -1;
            else
                mn = 1;
            array[i] = rd * mn;
        }
        else
        {
            printf("%d) ", i + 1);
            scanf_s("%d", &array[i]);
        }
    }
    if (choice == 1)
    {
        printf("  ");
        for (int i = 0, j = 1; i < amount; i++, j++)
        {
            printf("%d  ", array[i]);
            if (j == 10)
                printf("\n  ");
        }
    }


    int min = array[0], indMin = 0;
    for (int i = 0; i < amount; i++)
    {
        if (min > array[i])
        {
            min = array[i];
            indMin = i;
        }
    }

    int max = array[0], indMax = 0;
    for (int i = 0; i < amount; i++)
        if (max <= array[i])
        {
            max = array[i];
            indMax = i;
        }

    if (min == max || indMin - indMax == 1 || indMax - indMin == 1)
    {
        printf("\n Try again!");
        return 0;
    }

    int fst = 0, scn = 0;
    if (indMax > indMin)
    {
        fst = indMin;
        scn = indMax;
    }
    else
    {
        fst = indMax;
        scn = indMin;
    }

    for (int k = fst + 1; k < scn; k++)
    {
        for (int i = k + 1; i < amount; i++)
            array[i - 1] = array[i];
        amount--;
        scn--;
        k--;
    }

    printf("\n \n \n");

    for (int i = 0, j = 1; i < amount; i++, j++)
    {
        printf("%d\t", array[i]);
        if (j % 10 == 0) printf("\n");
    }

    return 0;
}