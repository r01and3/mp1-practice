#include <stdio.h>

void main()
{
	unsigned short i = 567;
	char* a = (char*) &i;
	printf("%d %d", *a, *(a + 1));	
}