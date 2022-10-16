#include <stdio.h>
int main()
{
	float x1, y1, x2, y2, x3, y3, a, b, X, Y, Z;
	printf("Coordinates of point A: \n");
	scanf_s("%f %f", &x1, &y1);
	printf("Coordinates of point B: \n");
	scanf_s("%f %f", &x2, &y2);
	printf("Coordinates of point C: \n");
	scanf_s("%f %f", &x3, &y3);
	printf("Coordinates of point M: \n");
	scanf_s("%f %f", &a, &b);
	X = (x1 - a) * (y2 - y1) - (x2 - x1) * (y1 - b);
	Y = (x2 - a) * (y3 - y2) - (x3 - x2) * (y2 - b);
	Z = (x3 - a) * (y1 - y3) - (x1 - x3) * (y3 - b);
	if (X > 0 && Y > 0 && Z > 0)
		printf("Point M is inside");
	else if (X < 0 && Y < 0 && Z < 0)
		printf("Point M is inside");
	else printf("Point M is outside");
	return 0;
}