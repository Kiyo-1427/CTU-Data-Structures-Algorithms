#include<stdio.h>
#define MaxLength 80
typedef struct{
    char Data[MaxLength]; //Phần tử
    int n; // Số ký tự
}Line;
void printLine(Line L){
    int i;
    for(i = 0; i<L.n;i++){
        printf("%c",L.Data[i]);

    }
    printf("\n");
}