#include<stdio.h>
#include<conio.h>
#define Maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Elements[Maxlength];
    Position Last;
}List;

void printList(List L){
    int i;
    for(i =0;i < L.Last;i++){
        printf("%d ",L.Elements[i]);
    }
}