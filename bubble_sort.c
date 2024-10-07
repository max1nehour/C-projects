//
//  main.c
//  hw6-2
//
//  Created by M1HR on 2022/5/2.
//
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define row 10
#define col 10

int main(){
    int i,j,temp;
    int n = 0;
    int a[row][col];
    //開頭
    printf("Enter the order of matrix:");
    scanf("%d",&n);
    //若陣列大小大於10或小於3則終止程式
    assert(n>=3 && n<=10);
    //產生介於10-100的亂數 並賦值給陣列
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            int r=rand()%90+10;
            a[i][j]=r;
        }
    }
    //列印陣列
    printf("Array elements:\n");
    for (i=0;i<n;i++) {
       for (j=0;j<n;j++) {
          printf("%4d",a[i][j]);
       }
        printf("\n");
    }
    //泡沫排序法
    for (i=0;i<n*n-1;i++){
        for (j=0;j<n*n-1-i;j++){
            if (a[j/n][j%n] < a[(j+1)/n][(j+1)%n]){
                temp = a[j/n][j%n];
                a[j/n][j%n] = a[(j+1)/n][(j+1)%n];
                a[(j+1)/n][(j+1)%n] = temp;
            }
        }
    }
    //列印排序後的陣列
    printf("\nArray after sorting:\n");
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            printf("%4d",a[i][j]);
        }
    printf("\n");
    }
}
