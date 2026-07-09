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
