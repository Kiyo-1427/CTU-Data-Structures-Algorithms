#include <stdio.h>
#define MaxLength 80
typedef struct
{
    char Data[MaxLength]; // Phần tử
    int n;                // Số ký tự
} Line;

int isEmpty(Line L){
    return L.n ==0;
}
