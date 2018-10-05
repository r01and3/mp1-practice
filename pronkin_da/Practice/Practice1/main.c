#include <stdio.h>
#include <math.h>
#include <locale.h>
#define PDSP 0.0007
#define PDVP 0.0009
#define WOOD 0.00065

void main() {
	setlocale(LC_ALL, "Rus");
	float h, w, d, m;
	int i = 0;
	m = 0;
	while (i == 0)
	{	
		printf("������� ������ h (180 - 220 ��), ������ w (80 - 120 ��) � ������� d (50 - 90 ��)\n");
		scanf("%f %f %f", &h, &w, &d);
		if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90)
		{
			printf("������� ������������ �������, ��������� ����.\n");
		}
		else
		{
			i = 1;
		}
	}
	m = m + PDVP*h*w*0.5f;//m + ������ ������
	m = m + PDSP*(h + w)*d*3.0f;//m + ��� �������� + ��� �������� 
	m = m + WOOD*h*w;//m + �����
	if (h > 200)
	{
		m = m + PDSP*w*d*5.0f;//m + �����
	}
	else
	{
		m = m + PDSP*w*d*4.0f;//m + �����
	}
	printf("����� ����� = %f", m);
}