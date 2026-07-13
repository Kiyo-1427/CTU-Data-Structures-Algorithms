#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *Header){
    (*Header)=(struct Node*)malloc(sizeof(struct Node));
    (*Header)->Next == NULL;
}

void append(ElementType x, List *pL){
    Position last = (*pL); //phải cho nó chạy từ toa đầu
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element =x;
    t->Next = NULL;
    while(last->Next != NULL){
        last = last->Next;
    }
    last->Next = t;
}

void copyEvenNumbers(List L1, List *pL2){
    Position p = L1->Next;
    makenullList(pL2);
    for(; p != NULL; p = p->Next){
        if(p->Element % 2 == 0){
            append(p->Element,pL2);
        }
    }
}

