#include <stdio.h>
int main()
{
    int m, n, p, count = 0;
    printf("M is equal to ");
        scanf_s("%d", &m);
    printf("N is equal to ");
        scanf_s("%d", &n);
    printf("P is equal to ");
        scanf_s("%d", &p);
        if (m < 0) count++;
        if (n < 0) count++;
        if (p < 0) count++;
        printf("Amount of negative numbers: %d", count);
    return 0;
}