#include <stdio.h>

int t, n;
int d[50][2] = {1,0, 0,1};

int main()
{
    for(int i=2; i<=40; i++) {
        d[i][0] = d[i-1][0]+d[i-2][0];
        d[i][1] = d[i-1][1]+d[i-2][1];
    }
    
    for(scanf("%d",&t); t--;)
    {
        scanf("%d", &n);
        printf("%d %d\n", d[n][0], d[n][1]);
    }
}
