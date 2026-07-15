#include<stdio.h>

#define SoPhanTu 100

typedef struct{
    int DuLieu[SoPhanTu];
    int Dinh;
}NganXep;

void them(int x, NganXep *pS){
    if(pS->Dinh == 0){
        printf("Loi! Ngan xep day!");
    }else{
        pS->Dinh-=1;
        pS->DuLieu[pS->Dinh]=x;
    }
}