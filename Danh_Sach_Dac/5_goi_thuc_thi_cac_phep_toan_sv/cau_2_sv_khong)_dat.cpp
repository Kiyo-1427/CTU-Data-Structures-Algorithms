#include <stdio.h>
#include <string.h>
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

void dsRong(DanhSach *pL)
{
    pL->n = 0;
}

void nhap(DanhSach *pL)
{
    int n, i;
    scanf("%d", &n);
    // BẮT BUỘC PHẢI CÓ DÒNG NÀY ĐỂ CẬP NHẬT SỐ LƯỢNG VÀO DANH SÁCH
    pL->n = n;
    for (i = 0; i < n; i++)
    {
        scanf("%s", pL->A[i].MSSV);
        // Có khoảng trắng đầu tiên và chặn \r\n
        scanf(" %[^\r\n]", pL->A[i].HoTen);
        scanf("%f %f %f", &pL->A[i].DiemLT, &pL->A[i].DiemTH1, &pL->A[i].DiemTH2);
    }
}

int tim(char maSV[], DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        if (strcmp(L.A[i].MSSV, maSV) == 0)
        {
            return i + 1;
        }
    }
    return L.n + 1;
}

void in(DanhSach L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}

void xoa(int p, DanhSach *pL)
{
    int i;
    // pL->n-1 vì thằng ở cuối tối đa, biến sau còn có i+1
    for (i = p - 1; i < pL->n - 1; i++)
    {
        pL->A[i] = pL->A[i + 1];
    }
    pL->n--;
}
void chen(int p,DanhSach x,DanhSach *pL){
    pL->A[pL->n] = x.A[p-1];
    pL->n++;
}

int main()
{
    float tong;
    int i;
    DanhSach L;
    dsRong(&L);
    DanhSach kq;
    dsRong(&kq);
    nhap(&L);
    for(i = 0; i < L.n;i++){
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if(tong < 4.0){
            chen(i+1,L, &kq);
        }

    }
    in(L);
    if(kq.n >0){
        printf("Sinh vien KHONG DAT\n");
        in(kq);
    }
    return 0;
}
/* có thể làm như sau để tối ưu
void chepKhongDat(DanhSach L, DanhSach *pKq) {
    dsRong(pKq); // Đảm bảo danh sách kết quả khởi đầu trống rỗng
    int i;
    float tong;
    for (i = 0; i < L.n; i++) {
        tong = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        // Nếu tổng điểm < 4.0, chép trực tiếp sinh viên đó sang danh sách kq
        if (tong < 4.0f) {
            pKq->A[pKq->n] = L.A[i];
            pKq->n++;
        }
    }
}

int main() {
    DanhSach L, kq;
    dsRong(&L);
    
    // 1. Nhập danh sách
    nhap(&L);
    
    // 2. In danh sách ban đầu trước theo đúng format Output
    in(L);
    
    // 3. Lọc ra danh sách sinh viên không đạt
    chepKhongDat(L, &kq);
    
    // 4. Kiểm tra và in danh sách không đạt (nếu có)
    if (kq.n > 0) {
        printf("Sinh vien KHONG DAT\n");
        in(kq);
    }
    
    return 0;
}*/