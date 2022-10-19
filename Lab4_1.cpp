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

    printf("Enter the side of the matrix: ");
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
            printf(" %d ", arr[i][j]);

        printf("\n");
    }


    int res = 0, count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] >= 0)
                count++;
        }
        if (count == row)
        {
            for (int j = 0; j < col; j++)
            {
                res += arr[i][j];
            }
            count = 0;
        }
        else count = 0;
    }

    if (res == 0)
        printf("\nAll rows have negative numbers");
    else
        printf("\nRes is %d\n", res);

    int sum = 0, minsum = 0, j = 0, i = 0;
    for (int s = 0; s < (row - 1); s++)
    {
        if (j >= row) break;
        i = s; j = 0;
        for (j; j < row; j++)
        {
            i++;
            if (i >= row) break;
            sum += arr[i][j];
        }
        if (sum < minsum) minsum = sum;
        sum = 0;
    }
    j = 0; i = 0; sum = 0;
    for (int s = 0; s < (row - 1); s++)
    {
        if (i >= row)
            break;
        j = s, i = 0;
        for (i; i < row; i++)
        {
            j++;
            if (j >= row)
                break;
            sum += arr[i][j];
        }
        if (sum < minsum) minsum = sum;
        sum = 0;
    }
    printf("\n%d is the min sum\n", minsum);

    return 0;
}