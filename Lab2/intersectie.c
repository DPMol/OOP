#include <stdio.h>

typedef struct {
    int x,y;
}   coord;

typedef struct {
    coord A,B;
}   seg;

int max(int a, int b){
    if (a>=b)
        return a;
    else
        return b;
}

int min(int a, int b){
    if (a<=b)
        return a;
    else
        return b;
}

void displaycoord(coord P){
    printf("(%d,%d)",P.x,P.y);
}

coord maxcoord(coord a, coord b){
    if (a.x + a.y >= b.x + b.y)
        return a;
    return b;
}

coord mincoord(coord a, coord b){
    if (a.x + a.y >= b.x + b.y)
        return b;
    return a;
}

void col(coord a,coord b,coord c,coord d){
    int aux;
    if (a.x+a.y <=b.x+b.y) {
        aux = a.x;
        a.x = b.x;
        b.x = aux;
        aux = a.y;
        a.y = b.y;
        b.y = aux;
    }

    if (c.x+c.y <=d.x+d.y) {
        aux = c.x;
        c.x = d.x;
        d.x = aux;
        aux = c.y;
        c.y = d.y;
        d.y = aux;
    }

    if((c.y + c.x >= b.x + b.y )&& (d.x + d.y <= a.x+ a.y)){
        printf("Intre: ");
        displaycoord(maxcoord(b,d));
        displaycoord(mincoord(a,c));
        
    }
    else
        printf("Segmentele nu se intersecteaza col");

}

void intersect(coord a,coord b,coord c,coord d){

    int a1 = b.y - a.y;
    int b1 = a.x - b.x;
    int c1 = a1*a.x + b1*a.y;

    int a2 = d.y - c.y;
    int b2 = c.x - d.x;
    int c2 = a2*c.x + b2*c.y;

    int determinant = a1*b2 - a2*b1;

    if(determinant == 0){
        if(c1 == c2)
            col(a,b,c,d);
        else
            printf("Segmentele nu se intersecteaza");}
    else{
        float x,y;
        x = (float) (b2*c1 - b1*c2)/determinant;
        y = (float) (a1*c2 - a2*c1)/determinant;
        
        if((min(a.x, b.x) <= x && x<=max(a.x,b.x) && min(a.y,b.y)<=y && y<=max(a.y,b.y)) && (min(d.x, c.x) <= x && x<=max(c.x,d.x) && min(d.y,c.y)<=y && y<=max(d.y,c.y)))
            printf("(%f,%f)",x,y);
        else
            printf("Segmentele nu se intersecteaza");
    }
    
}

int main(){
    coord a,b,c,d;
    printf("Dati coordonatele la primul punct: ");
    scanf("%d , %d", &a.x,&a.y);
    printf("Dati coordonatele la al doilea punct: ");
    scanf("%d , %d", &b.x,&b.y);
    printf("Dati coordonatele la al treilea punct: ");
    scanf("%d , %d", &c.x,&c.y);
    printf("Dati coordonatele la al patrulea punct: ");
    scanf("%d , %d", &d.x,&d.y);


    intersect(a,b,c,d);

    return 0;
}