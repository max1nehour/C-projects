//
//  main.c
//  midterm
//
//  Created by M1HR on 2022/5/9.
//
#include <stdio.h>

void function(int, int, int);

int main() {
    int n,head=0,tail=28,middle=14;
    int a[15];
    
//    定義陣列
    for (int i=0;i<15;i++){
        a[i] = 2*i;
    }
    
//    輸入尋找值
    printf("Enter a number between 0 and 28 : ");
    scanf("%d",&n);
    printf("\n");
    
//    印出陣列之指標
    printf("Subscripts :\n");
    for(int i=0;i<15;i++){
        printf("%4d",i);
    }

//    印出陣列值
    printf("\n--------------------------------------------------------------\n");
    for (int i=0;i<15;i++){
        printf("%4d",a[i]);
        if (middle==a[i]){
            printf("*");
     }
    }
    printf("\n");
    
//    函式的工作就來囉
    while(head<tail){
    
    if(n>middle){
        head = middle+2;
        middle=(head+tail)/2;
        for(int a=0;a<head/2;a++){
            printf("\t");
        }
        function(head,tail,middle);
        printf("\n");
        
        }
    if(n<middle){
        tail = middle-2;
        middle=(head+tail)/2;
        for(int a=0;a<head/2;a++){
            printf("\t");
        }
        function(head,tail,middle);
        printf("\n");
            
    }
    
    else if (middle==n){
        printf("\n%d found in array element %d\n",n,middle/2);
        break;
    }
}
    if(n!=middle){
        printf("\n%d not found",n);
    }
    printf("\n");
}
    
void function(int x, int y, int z){
    //要初始化array的值
    int a[15]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28};
    for (int i=x/2;i<y/2+1;i++){
        printf("%4d",a[i]);
        if(a[i]==z){
            printf("*");
      }
    }
}
