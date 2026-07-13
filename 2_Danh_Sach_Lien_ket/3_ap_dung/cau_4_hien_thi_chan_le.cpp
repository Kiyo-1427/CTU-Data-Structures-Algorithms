#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;
void makenullList(List *Header)
{
    (*Header) = (struct Node *)malloc(sizeof(struct Node));
    (*Header)->Next = NULL;
}
 
void printlist(List L){
    Position p = L->Next;
    for(; p!=NULL; p =p->Next){
        printf("%d ", p->Element);
    }
    printf("\n");
}

void append(ElementType x, List *pL){
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next= NULL;
    Position last = (*pL);
    while(last ->Next != NULL){
        last= last->Next;
    }
    last->Next = t;
}

void readlist(List *pL){
    makenullList(pL);
    int n, i;
    ElementType x;
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        scanf("%d",&x);
        append(x, pL);
    }
}
List docchan(List L){
    List kq;
    makenullList(&kq);
    Position p = L->Next;
    for(; p !=NULL; p = p->Next){
        if(p->Element % 2 == 0){
            append(p->Element, &kq);
        }
    }
    return kq;
}


List docle(List L){
    List kq;
    makenullList(&kq);
    Position p = L->Next;
    for(; p !=NULL; p = p->Next){
        if(p->Element  & 1){
            append(p->Element, &kq);
        }
    }
    return kq;
}

int main (){
    List L, chan, le;
    readlist(&L);
    chan = docchan(L);
    le = docle(L);
    printlist(L);
    printlist(le);
    printlist(chan);
    return 0;
}