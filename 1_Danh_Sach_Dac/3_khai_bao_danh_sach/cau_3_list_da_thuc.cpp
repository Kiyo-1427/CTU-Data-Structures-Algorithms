// 1. Khai báo cấu trúc Đơn thức (thêm chữ DonThuc sau chữ struct)
typedef struct DonThuc
{
    double he_so; // Hệ số
    int bac;      // Bậc (số mũ)
} DonThuc;

// 2. Khai báo cấu trúc Đa thức (thêm chữ DaThuc sau chữ struct)
typedef struct DaThuc
{
    DonThuc A[100]; // Mảng A chứa tối đa 100 đơn thức
    int so_luong;   // Số lượng đơn thức thực tế
} DaThuc;

/*test
struct DaThuc d={{{1.5,1}}, 1};
printf("Size A = %lu x %lu\n",
    sizeof(d.A)/sizeof(DonThuc), sizeof(DonThuc));
printf("n = %d\n", d.so_luong);
*/
// vì trong test sử dụng tên khai sinh, struct Dathuc nên cần khai báo typedef struct Dathuc