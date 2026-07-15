#define SoPhanTu 100 // Định nghĩa hằng số M = 100 theo đề bài

// Định nghĩa cấu trúc Ngăn xếp
typedef struct {
    int DuLieu[SoPhanTu]; // Mảng chứa các số nguyên của ngăn xếp
    int Dinh;             // Chỉ số của phần tử nằm ở đỉnh ngăn xếp
} NganXep;


int giatriDinh(NganXep S) {
    return S.DuLieu[S.Dinh];
}