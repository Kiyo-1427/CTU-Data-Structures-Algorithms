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