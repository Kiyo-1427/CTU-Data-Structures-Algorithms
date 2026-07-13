#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node{
    ElementType Element;
    struct Node* Next;
};

typedef Node* Position;
typedef Position List;

void makenullList(List *header){
    (*header)=(Node*)malloc(sizeof(Node));
    (*header)->Next=NULL;
}

void addFirst(ElementType x,List *L){
    //vì List bản chất là position mà position là con trỏ nên *L kiểu List là con trỏ cấp 2 cần truy cập thì phải thêm *L
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next = (*L)->Next;
    (*L)->Next=t;
}

void sort(List *pL){
    Position p,q;
    ElementType temp;
    if(*pL == NULL || (*pL)->Next == NULL){
        return;
    }
    for(p = (*pL)->Next; p != NULL ; p = p->Next){
        for(q = p->Next; q != NULL; q = q->Next){
            if(q->Element < p->Element){
                temp = p->Element;
                p->Element = q->Element;
                q->Element = temp;
            }
        }
    }
}
