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



void addFirst(ElementType x,List *pL){
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    (*pL)->Next = t->Next;
    (*pL)->Next = t;
}



void sort(List *pL){
    Position p, q;
    ElementType temp;
    for(p = (*pL)->Next; p != NULL; p= p->Next){
        for(q=p->Next;q !=NULL; q= q->Next){
            if(p->Element > q ->Element){
                temp = p->Element;
                p->Element = q->Element;
                q->Element = temp;

            }
        }
    }
}
