#include<stdio.h>
#define MaxLength 80
typedef struct{
    char Data[MaxLength]; //Phần tử
    int n; // Số ký tự
}Line;

void appendChar(char x, Line *pL){
    pL->Data[pL->n]=x;
    pL->n++;
}

void  appendLine(Line *pDestination, Line Source){
    int i;
    for(i = 0;i< Source.n;i++){
        //không cần thêm dấu cách vì bản thân L2 đã có sẵn cách rồi
        appendChar(Source.Data[i], pDestination);
    }
}