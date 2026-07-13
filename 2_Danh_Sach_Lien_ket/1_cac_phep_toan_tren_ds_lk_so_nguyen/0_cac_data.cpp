#include<stdio.h>
#include<conio.h>
#include<atlalloc.h>
typedef int ElementType; //đổi tên cho sang
typedef struct Node{
    ElementType Element;
    struct Node* Next; // Trong lòng Struct khi chưa định nghĩa xong, bắt buộc phải viết 'struct Node, con trỏ kiểu chính nó, bên trong có con trỏ
};

typedef Node* Position; //đổi tên để hiểu nghĩa, thằng này là culi
typedef Position List; // đổi tên thằng này cố định trưởng tàu
//tạo ds rỗng
void MakeNULL_List(List *Header){
    (*Header) = (Node*)malloc(sizeof(Node));
    //cần cất giữ đất xin = sizeof(Node) kêu tính kích thước bản vẽ cái nha Node, malloc(Kích thước) đi xin thằng hệ thống đúng mảnh đất có kích thước vừa đo, (Node*) ép kiểu để cho thăng hệ thống biết sẽ xây cái gì trên mảnh đất đó
    (*Header)->Next = NULL; // cái thằng này đang cầm tờ giấy trắng ko có địa chỉ
}
//kiểm tra danh sách rỗng
int Empty_List (List L){
    return (L->Next == NULL);
}

//thêm x vào p
void Insert_List (ElementType X, Position P, List *L){
    Position T;
    T = (Node*)malloc(sizeof(Node));
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}
//xóa tại p, chuẩn là xóa sau p, vì nx sẽ cố hàm locate tìm thằng trước x tên là p, xóa p nghĩa là xóa sau x là chuẩn
void Delete_List(Position P, List *L){
    Position T;
    if(P->Next != NULL){
        T = P->Next;
        P->Next = P->Next->Next;
        free(T);
    }else{
        printf("\nLoi !Khong co phan tu phia sau de xoa");
    }
}

//hàm vị trí phần tử đầu tiên có nội dung x
Position Locate(ElementType X, List L){
    Position P = L;
    int found = 0;
    while ((P->Next != NULL) && (found == 0)){
        if(P->Next->Element == X){
            found = 1;
        }else{
            P = P->Next;
        }
    }
    return P;
}
//hàm lấy nội dung x tại vị trí P thực ra là sau p
ElementType Retrive(Position P, List L){
    if(P->Next != NULL){
        return P->Next->Element;
    }
}
//phần tử đâu tiên trong ds
Position First(List L){
    return L;
}


//phần tử cuối cùng trong ds
Position EndList(List L){
    Position P;
    P = First(L);
    while (P->Next != NULL){
        P = P->Next;
        return P;
    }
}

//vị trí phần tử kế tiếp
Position Next(Position P, List L){
    return P->Next;
}

//vị trí xuẩt hiện lần thứ i của x
Position MyLocate(ElementType x, int i,List L ){
    Position p = First (L);
    int count = 0;
    while (Next(p,L) != NULL &&  count < i){
        if(Retrive(p,L) == x){
            count ++;
        }
        if(count < i){
            p = Next(p, L);
        }
    }
    return p;
}