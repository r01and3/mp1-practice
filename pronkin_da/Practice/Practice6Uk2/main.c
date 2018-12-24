#include <stdio.h>

void main() 
{
	char a[] = { 55, 2 };
	unsigned short b = *((unsigned short*)a);
	printf("%d", b);
}