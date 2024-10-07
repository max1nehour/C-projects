//
//  main.c
//  hw5
//
//  Created by M1HR on 2022/4/17.
//

#include <stdio.h>

double sqrt(double); //宣告根號函式
double Length(double,double); //宣告Length函式

int main(){

    int x=3, y=4;
    printf("Before Normalize: (x,y)=(%d,%d)\n",x,y);
    printf("After Normalize: (x,y)=(%.1f,%.1f)\n",x/Length(x,y),y/Length(x,y));
    //呼叫函式length來標準化向量（x,y)
    return 0;
}

double Length (double x,double y){
    return sqrt(x*x+y*y); //回傳向量x,y的長度
}
