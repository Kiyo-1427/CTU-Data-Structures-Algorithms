#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef Node *Position;
typedef Position List;

void deleteList(Position p,List *pL){
    Position t;
    if(p->Next != NULL){
        p->Next = t;
        p->Next = p->Next->Next;
        free(t);
    }else{
        return;
    }
}

void normalize(List *pL) {
    Position p, q;
    p = (*pL); //vì còn thêm thằng q phía sau nx nếu cho p = (*pL)->Next thì sẽ luôn tồn tại 2 vị trí thực trên toa v thì cho dù giống nó cx ko xóa
    if(*pL == NULL || (*pL)->Next==NULL){
        return;
    }
    while(p->Next != NULL){
        q = p->Next;
        while(q->Next != NULL){
            if(p->Next->Element == q->Next->Element){
                delete(q,pL);
            }else{
                q= q->Next;
            }
        }
        p= p->Next;
    }
}

