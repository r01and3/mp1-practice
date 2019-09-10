#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float m = 0, h, w, d, pdsp, pdvp, wood;
	setlocale(LC_ALL, "Rus");
	printf("������� ������ h (180 - 220 ��), ������ w (80 - 120 ��) � ������� d (50 - 90 ��)\n");
	scanf("%f %f %f", &h, &w, &d);
	if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90)
	{
		printf("������� ������������ �������, ��������� ����.\n");
		return;
	}
	h /= 100.0f;
	w /= 100.0f;
	d /= 100.0f;
	printf("������� ��������� ���, ���, ������ � ��/�3.\n");
	scanf("%f %f %f", &pdsp, &pdvp, &wood);
	if (pdsp == 0 || pdvp == 0 || wood == 0)
	{
		printf("��������� �� ����� �������� ��� ���� ������ ����.\n");
		return;
	}
	m += pdvp * h * w * 0.005f;
	m += 2.0f * pdsp * h * d * 0.015f;
	m += 2.0f * pdsp * w * d * 0.015f;
	m += wood * h * w * 0.01f;
	m += (h - 2.0f * 0.015f) / (0.4f + 0.015f) * (w - 2.0f * 0.015f) * (d - 0.005f) * 0.01f * pdsp;
	printf("����� ����� = %f ", m);
}