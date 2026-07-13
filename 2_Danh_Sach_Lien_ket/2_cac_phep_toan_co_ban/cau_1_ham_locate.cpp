#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List; 

Position  locate(ElementType x, List L){
    Position p = L;
    int count = 0;
    while (p->Next != NULL && count == 0){//phải là p->next trảnh kiểm túi bóng ma p->Next->Element==x
        if(p->Next->Element==x){
            count =1;
        }else{
            p = p->Next;
        }
    }
    return p;
}
