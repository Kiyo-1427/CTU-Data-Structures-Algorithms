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
int member(ElementType x, List L)
{
    Position p = L->Next;
    for (; p != NULL; p = p->Next)
    {
        if (p->Element == x)
        {
            return 1;
        }
    }
    return 0;
}


List intersection(List L1, List L2){
    List kq;
    makenullList(&kq);
    Position p = L1->Next;
    for(; p != NULL; p = p->Next){
        if(member(p->Element, L2)){
            append(p->Element, &kq);
        }
    }
    return kq;
}
