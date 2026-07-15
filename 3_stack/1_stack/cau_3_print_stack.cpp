#include<stdio.h>

#define SoPhanTu 100

typedef struct{
    int DuLieu[SoPhanTu];
    int Dinh;
}NganXep;

int giatriDinh(NganXep S){
    return S.DuLieu[S.Dinh];
}

int ktRong(NganXep S){
    return S.Dinh==SoPhanTu;
}

void xoa(NganXep *pS){
    if(ktRong(*pS)){
        printf("Loi! stack rong");
    }else{
        pS->Dinh++;
    }
}
void hienthi(NganXep *pS) {
    // Tạo một ngăn xếp tạm sao chép nguyên vẹn dữ liệu từ *pS
    NganXep S_tam = *pS;
    
    // Vòng lặp duyệt qua ngăn xếp tạm theo đúng gợi ý của thầy
    while (ktRong(S_tam) == 0) {
        // Xử lý (in) phần tử tại đỉnh ngăn xếp tạm
        printf("%d\n", giatriDinh(S_tam));
        
        // Xóa phần tử tại đỉnh ngăn xếp tạm
        xoa(&S_tam);
    }
}

void khoitao(NganXep *pS){
    pS->Dinh = SoPhanTu;
}