#include <stdio.h>
#include <string.h> // Bắt buộc phải có để dùng hàm strcmp


//khai báo độ dài mảng
#define Maxlength 100
//đổi tên thằng int cho sang mồm
typedef int ElementType;
typedef int Position;
//tạo struct list
typedef struct{
    ElementType Elements[Maxlength];
    Position Last;
}List;

void sort(List *pL){
    int p, q;
    ElementType temp;
    for(p = 0; p< pL->Last-1;p++){
        for(q = p + 1; q <pL->Last;q++){
            if(pL->Elements[p]> pL->Elements[q]){
                temp = pL->Elements[p];
                pL->Elements[p]=pL->Elements[q];
                pL->Elements[q]=temp;
            }
        }
    }
}

void  deleteList(Position p, List *pL){
    int i;
    if(p >= pL->Last || p == 0){
        printf("Vi tri khong hop le\n");
    }else{
        for(i = p-1; i<pL->Last-1;i++){
            pL->Elements[i]=pL->Elements[i+1];

        }
        pL->Last--;
    }
}


void normalize(List *pL){
    int i,j;
    for( i = 0; i<pL->Last;i++){
         for( j = i+1; j<pL->Last;j++){
        if(pL->Elements[i]==pL->Elements[j]){
            deleteList(j, pL);

        }
    }
    }
}