// 1. Khai báo cấu trúc của 1 Sinh Viên (Khuôn nhỏ)
typedef struct
{
    char MSSV[10];  // Mã số sinh viên (chuỗi 10 ký tự)
    char HoTen[50]; // Họ và tên (chuỗi 50 ký tự)
    float DiemLT;   // Điểm thi lý thuyết
    float DiemTH1;  // Điểm thi thực hành 1
    float DiemTH2;  // Điểm thi thực hành 2
} SinhVien;

// 2. Khai báo cấu trúc của Danh sách đặc (Khuôn lớn)
typedef struct
{
    SinhVien A[40]; // Mảng A chứa tối đa 40 phần tử SinhVien
    int n;          // Số lượng phần tử thực tế trong danh sách
} List;