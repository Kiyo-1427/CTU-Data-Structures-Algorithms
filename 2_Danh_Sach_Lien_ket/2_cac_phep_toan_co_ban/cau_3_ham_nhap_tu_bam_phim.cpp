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

void makenullList(List *header){
    (*header)=(Node*)malloc(sizeof(Node));
    (*header)->Next=NULL;
}

void readList(List *pL){
    makenullList(pL);
    
    // Tạo một culi chuyên giữ đuôi tàu, ban đầu nó đứng ở Header
    Position last = *pL; 
    
    int n, i;
    ElementType x;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        
        // 1. XIN ĐẤT Ở TRONG VÒNG LẶP: Mỗi con số là 1 toa tàu hoàn toàn mới!
        Position t = (Position)malloc(sizeof(struct Node));
        t->Element = x;
        t->Next = NULL; // Chốt đuôi an toàn cho toa mới
        
        // 2. Móc toa mới này vào đuôi đoàn tàu hiện tại
        last->Next = t;
        
        // 3. Dời thằng culi 'last' xuống toa vừa mới thêm để nó tiếp tục giữ đuôi
        last = t;
    }
}

