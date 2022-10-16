#include <stdio.h>
#include <time.h>
#include<stdlib.h>


int main()
{
    srand(time(NULL));
    int row, col, choice, rd;
    int arr[100][100];

    printf("How to enter numbers:\n1)Random numbers\n2)From the keyboard\n");

    while (scanf_s("%d", &choice) != 1 || choice != 1 && choice != 2 || getchar() != '\n')
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }

    printf("Enter the side of the matrix ");
    while (scanf_s("%d", &row) != 1 || row > 100 || row <= 0 || getchar() != '\n')
    {
        printf("Wrong input!\n");
        rewind(stdin);
    }
    col = row;

    if (choice == 1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                rd = rand() % 11;
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
            printf(" %d ", arr[i][j]);

        printf("\n");
    }

    printf("\n\n");

    int min = arr[0][col / 2 + col % 2];
    for (int i = 0; i < row / 2; i++)
    {
        for (int j = col / 2 + col % 2; j < col; j++)
        {
            if (min > arr[i][j])
                min = arr[i][j];
        }
    }

    printf("\nMin is %d\n", min);

    return 0;
}