#include <stdio.h>

int a, b;

int main()
{
    scanf("%d %d", &a, &b);
	printf("%.15lf", (double)a/b);
}
