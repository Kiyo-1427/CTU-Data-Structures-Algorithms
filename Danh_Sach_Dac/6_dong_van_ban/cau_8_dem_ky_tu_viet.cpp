#include <stdio.h>
#define MaxLength 80
typedef struct
{
    char Data[MaxLength]; // Phần tử
    int n;                // Số ký tự
} Line;

int countAlphabet(Line L)
{
    int i, t = 0;
    for (i = 0; i < L.n; i++)
    {
        // có thể (L.Data[i] >= 'A' && L.Data[i] <= 'Z') || (L.Data[i] >= 'a' && L.Data[i] <= 'z')
        if ((L.Data[i] >= 65 && L.Data[i] <= 90) || (L.Data[i] >= 97 && L.Data[i] <= 122))
        {
            t++;
        }
    }
    return t;
}
