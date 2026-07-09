#include <stdio.h>
#include <conio.h>
#define Maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct
{
    ElementType Elements[Maxlength];
    Position Last;
} List;

int member(ElementType x, List L)
{
    int i;
    for (i = 0; i < L.Last; i++)
    {
        if (L.Elements[i] == x)
        {
            return 1;
        }
    }
    return 0;
}
