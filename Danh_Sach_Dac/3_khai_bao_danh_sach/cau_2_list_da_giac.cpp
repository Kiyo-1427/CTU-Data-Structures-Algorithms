// 1. Khai báo cấu trúc của 1 Điểm (Khuôn nhỏ)
typedef struct
{
    int x;
    int y;
} Point; // Nên đặt tên là Point (Điểm) thay vì A cho dễ nhớ nhé ca

// 2. Khai báo cấu trúc Đa giác bằng Danh sách đặc (Khuôn lớn)
typedef struct
{
    Point Dinh[100]; // Mảng chứa tối đa 100 điểm
    int n;           // Biến quản lý số lượng đỉnh thực tế của đa giác
} Polygon;           // Đặt tên đúng chuẩn Polygon đề bài yêu cầu