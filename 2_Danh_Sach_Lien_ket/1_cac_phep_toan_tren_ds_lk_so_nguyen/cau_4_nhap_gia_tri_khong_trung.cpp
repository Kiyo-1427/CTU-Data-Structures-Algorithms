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
int member(ElementType x, List L){
    Position p = L->Next;
    for(; p != NULL; p = p->Next){
        if(p->Element == x){
            return 1;
        }
    }
    return 0;
}

List readSet(){
    int n, i;
    List L;
    makenullList(&L);
    scanf("%d",&n);
    ElementType x;
    for(i = 0; i< n;i++){
        scanf("%d",&x);
        if(member(x, L)==0){
            addFirst(x, &L);
        }

    }
    return L;
}