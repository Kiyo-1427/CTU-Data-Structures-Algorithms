#include <stdio.h>
#include<string>
struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
};
typedef struct
{
    struct SinhVien A[40];
    int n;
} DanhSach;

void hienthiDat(DanhSach L){
    int i;
    float tong;
    for(i =0;i<L.n;i++){
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if(tong >= 4.0){
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, tong);
        }
    }
}

int xoaTai(int p, DanhSach *pL){
    if(p > pL->n || p<1){
        return 0;
    }
    int i;
    for(i = p-1; i< pL->n-1;i++){
        pL->A[i]=pL->A[i+1];
    }
    pL->n--;
    return 1;
}

DanhSach dsrong(){
    DanhSach L;
    L.n=0;
    return L;
}
void chenCuoi(struct SinhVien s, DanhSach *pL){
    pL->A[pL->n]=s;
    pL->n++;
}
DanhSach chepKhongDat(DanhSach L){
    DanhSach kq=dsrong();
    int i;
    float tong;
    for(i = 0; i< L.n;i++){
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if(tong <4.0){
            chenCuoi(L.A[i],&kq);
        }
    }
    return kq;

}

int tim(char maSV[], DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        if (strcmp(L.A[i].MSSV, maSV) == 0)
        {
            return i;
        }
    }
    return -1;
}

int ktRong(DanhSach L){
    return L.n==0;
}
DanhSach nhap(){
    DanhSach kq = dsrong();
    struct SinhVien s;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s.MSSV);
        scanf(" %[^\r\n]",s.HoTen);
        scanf("%f %f %f",&s.DiemLT,&s.DiemTH1,&s.DiemTH2);
        if(tim(s.MSSV,kq)==kq.n+1){
            chenCuoi(s,&kq);
        }
    }
}