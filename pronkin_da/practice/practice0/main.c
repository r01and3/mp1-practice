#include <stdio.h>
#include <math.h>

void main() {
	float x1, x2, y1, y2, r1, r2;
	printf("������� x � y ������ ���������� � r ������ ����������");
	scanf("%f %f %f", &x1, &y1, &r1);
	scanf("%f %f %f", &x2, &y2, &r2);
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) > fabs(r1 - r2) && sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < r1 + r2)
	{
		printf("���������� ������������");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) < fabs(r1 - r2))
	{
		printf("���� ���������� ����� ������ ������");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) > r1 + r2)
	{
		printf("���������� ����� �� ���������� ���� �� ����� � �� ������������");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == r1 + r2)
	{
		printf("���������� �������� ������� �������");
		return;
	}
	if (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) == r1 - r2)
	{
		printf("���������� �������� ���������� �������");
		return;
	}
}