#include<stdio.h>
#define MaxLength 80
typedef struct{
    char Data[MaxLength]; //Phần tử
    int n; // Số ký tự
}Line;

int locate(char x,Line L){
    int i;
    for(i = 0;i<L.n;i++){
        if(L.Data[i]==x){
            return i+1;
        }
    }
    return L.n+1;
}

