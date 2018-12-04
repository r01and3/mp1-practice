#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define K 20000

void choose(int a[], int n)
{
	int i, j, min, minidx;
	for (i = 0; i < n; i++)
	{
		min = a[i];
		minidx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < min)
			{
				minidx = j;
				min = a[j];
			}
		a[minidx] = a[i];
		a[i] = min;
	}
	return;
}

void insert(int a[], int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		tmp = a[i];
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			a[j] = tmp;
			j--;
		}
	}
}

void bubblesort(int a[], int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}

void countsort(int a[], int n)
{
	int i, j, b = 0;
	int count[K];
	for (i = 0; i < K; i++) count[i] = 0;
	for (i = 0; i < n; i++) count[a[i]]++;
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < count[i]; j++)
		{
			a[b] = i;
			b++;
		}
	}
}

void array_creation(int a[], int n)
{
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % K;
	}
}

void array_output(int a[], int n) 
{
	int i;
	for (i = 0; i < n; i++) printf("%d\n", a[i]);
}

void main()
{
	int i;
	int a[N];
	array_creation(a, N);
	array_output(a, N);
	countsort(a, N);
	for (i = 0; i < N; i++) printf("%d\n", a[i]);
}