#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[1000010];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    
    sort(a, a+n);
    
    for(int i=0; i<n; i++)
        printf("%d\n", a[i]);
    
    return 0;
}
