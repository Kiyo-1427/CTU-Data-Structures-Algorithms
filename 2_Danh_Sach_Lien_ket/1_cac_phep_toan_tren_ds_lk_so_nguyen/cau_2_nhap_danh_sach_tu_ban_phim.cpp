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

void readList(List *pL){
    int n,i;
    ElementType x;
    Position p, t;
    makenullList(pL);
    p = *pL;
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        scanf("%d",&x);
        t=(Position)malloc(sizeof(struct Node));
        //có thể viết t=(Node*)malloc(sizeof(struct Node)); vì position thực chất là con trỏ kiểu Node
        t->Element = x;
        t->Next = NULL;
        p->Next = t;
        p = p->Next;
    }
}
