#include <stdio.h>
#define MaxLength 80
typedef struct
{
    char Data[MaxLength]; // Phần tử
    int n;                // Số ký tự
} Line;

int locate(char x, Line L)
{
    int i;
    for (i = 0; i < L.n; i++)
    {
        if (L.Data[i] == x)
        {
            return i + 1;
        }
    }
    return L.n + 1;
}
int removeAt(int p, Line *pL)
{
    int i;
    for (i = p - 1; i < pL->n - 1; i++)
    {
        pL->Data[i] = pL->Data[i + 1];
    }
    pL->n--;
}

int erase(char ch, Line *pL)
{
    int x = locate(ch, *pL);
    if (x != pL->n + 1)
    {
        removeAt(x, pL);
        return 1;
    }
    else
    {
        return 0;
    }
}
