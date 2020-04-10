#include <stdio.h>
#include <string.h>

int d[30][30][30];

int w(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;
	if(a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	if(d[a][b][c] == -1)
	{
		if(a<b && b<c)
			d[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
		else
			d[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
	}

	return d[a][b][c];
}

int main()
{
	while(true)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1)
			break;

		memset(d, -1, sizeof(d));
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

	return 0;
}
