#include <stdio.h>
#include <time.h>
#include<stdlib.h>


int main()
{
    srand(time(NULL));
    int row, col, choice, rd;
    float arr[100][100];

    printf("How to enter numbers:\n1)Random numbers\n2)From the keyboard\n");

    while (scanf_s("%d", &choice) != 1 || choice != 1 && choice != 2 || getchar() != '\n')
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }

    printf("How many rows? ");
    while (scanf_s("%d", &row) != 1 || row > 100 || row <= 0 || getchar() != '\n')
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }
    printf("How many columns? ");
    while (scanf_s("%d", &col) != 1 || col > 100 || col <= 0 || getchar() != '\n')
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }

    if (choice == 1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                rd = rand() % 101;
                int min = rand() % 2;
                if (min == 0)
                    min = -1;
                else
                    min = 1;
                arr[i][j] = rd * min;
            }
        }
    }

    else
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("arr[%d][%d]=", i, j);
                while (scanf_s("%d", &arr[i][j]) != 1 || getchar() != '\n')
                {
                    printf("Wrong input!\n");
                    rewind(stdin);
                }
            }
        }
    }

    //Выводим массив на экран:
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf(" %.0f ", arr[i][j]);

        printf("\n");
    }

    int count = 0, j;
    float res = 0;
    for (j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (arr[i][j] < 0)
                count++;
        }
        if (count == row)
        {
            printf("\nNumber of the column is %d", j + 1);
            for (int i = 0; i < row; i++)
            {
                res += arr[i][j];
            }
            res = res / row;
            printf("\nRes is %.2f\n", res);
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                    arr[i][j] -= res;
            }

            printf("\n");
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                    printf(" %.2f ", arr[i][j]);

                printf("\n");
            }
            return 0;
        }
        else count = 0;
    }
    if (count == 0)
        printf("\nThere are no columns with only negative numbers!\n");

    return 0;
}