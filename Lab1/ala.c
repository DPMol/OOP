#include <stdio.h>

int main()
{

    int x,s =0;
    x =10;
    
    while (x!=0)
    {
        scanf("%d", &x);  
        s += x;
    }
    printf("%d", s);
    return 0;
}