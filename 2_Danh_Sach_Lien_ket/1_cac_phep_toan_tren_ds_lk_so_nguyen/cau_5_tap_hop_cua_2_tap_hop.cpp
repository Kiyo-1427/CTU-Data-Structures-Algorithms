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

void append(ElementType x, List *L) {
    // 1. Xin đất xây toa mới và nạp dữ liệu luôn
    Position p = (Position)malloc(sizeof(struct Node));
    p->Element = x;
    p->Next = NULL; // KHÓA ĐUÔI NGAY: Toa cuối cùng thì phía sau phải là NULL

    // 2. Phái một thằng culi xuất phát từ Đầu máy xe lửa để đi tìm đuôi tàu
    Position last = *L; 
    
    // Vòng lặp tìm toa cuối: Cứ thằng sau mà khác NULL thì culi tiến lên tiếp
    while (last->Next != NULL) {
        last = last->Next;
    }

    // 3. Lúc này culi 'last' đã đứng ở toa cuối cùng thật sự. 
    // Tiến hành móc toa mới p vào đuôi nó!
    last->Next = p;
}

List unionSet(List L1, List L2){
    List kq;
    makenullList(&kq);
    Position p = L1->Next;
    for(; p != NULL; p= p->Next){
        append(p->Element,&kq);
    }
    Position q = L2->Next;
    for(; q != NULL; q = q->Next){
        if(member(q->Element,kq)==0){
            append(q->Element, &kq);
        }
    }
    return kq;
}