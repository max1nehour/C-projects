//
//  main.c
//  hw9
//
//  Created by M1HR on 2022/5/22.
//

#include <stdio.h>

void sort(int*, int*, int*);

int main() {
    int a=9; int b=10; int c=8;
    sort(&a,&b,&c);//取址
    printf("Descending order of a, b, c: %d,%d,%d\n",a,b,c);
    printf("Enter your own three values:\n");
    scanf("%d%d%d",&a,&b,&c);
    sort(&a,&b,&c);
    printf("Descending order of entered three values: %d,%d,%d\n",a,b,c);
    return 0;
}

void sort(int *a, int *b, int *c){ //指標
    int temp;
    int *p1,*p2,*p3;
    p1=a;
    p2=b;
    p3=c;
    
    if(*p1<*p3){
        temp=*p1;
        *p1=*p3;
        *p3=temp;
    }
    if(*p1<*p2){
        temp=*p1;
        *p1=*p2;
        *p2=temp;
    }
    if(*p2<*p3){
        temp=*p2;
        *p2=*p3;
        *p3=temp;
    }
    
}

