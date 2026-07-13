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

void printOddNumbers(List L){
    // 1. Culi p xuất phát từ toa ĐẦU TIÊN CÓ DỮ LIỆU (bỏ qua Toa giả L)
    Position p = L->Next; 
    
    // 2. Đi dạo cho đến khi gặp ngõ cụt
    while(p != NULL){
        
        // 3. Khám balo của thằng p, không khám L
        if(p->Element & 1){ 
            printf("%d ", p->Element);
        }
        
        // 4. LUÔN LUÔN BƯỚC ĐI sau khi kiểm tra xong (Không để trong else)
        p = p->Next; 
    }
}

