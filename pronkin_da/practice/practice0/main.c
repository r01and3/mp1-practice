#include <stdio.h>
#include <math.h>

void main() {
	float x1, x2, y1, y2, r1, r2;
	printf("Введите x и y центра окружности и r радиус окружности");
	scanf("%f %f %f", &x1, &y1, &r1);
	scanf("%f %f %f", &x2, &y2, &r2);
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) > fabs(r1 - r2) && sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < r1 + r2)
	{
		printf("Окружности пересекаются");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < fabs(r1 - r2))
	{
		printf("Одна окружность лежит внутри другой");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) > r1 + r2)
	{
		printf("Окружности лежат на расстоянии друг от друга и не пересекаются");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == r1 + r2)
	{
		printf("Окружности касаются внешним образом");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == r1 - r2)
	{
		printf("Окружности касаются внутренним образом");
		return;
	}
}