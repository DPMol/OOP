#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prim(int x){
    if(x==2)
        return 1;
    if(x%2==0 || x ==1)
        return 0;
    for(int d = 3; d<=sqrt(x) ;d = d + 2){
        if(x%d==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf_s("%d", &n);
    if(n <=2 || n%2==1){
        printf("Nuop");
        exit(1);
    }
    int ok = 1, i = 2;
    while(ok == 1 && i<n){
        if(prim(i) && prim(n-i)){
            ok = 0;
            printf("Numarul este egal cu: %d + %d\n",i,n-i);
        }
        i++;
    }

}