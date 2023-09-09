#include <stdio.h>
#include <ctype.h>

int get_size(void);
void print_grid(int size);

int main (void) 
{
    int n=get_size();
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        printf("Enter size of grid: ");
        scanf("%d", &n);
    } 
    while (n<1 || n>8);
    return n;
}

void print_grid(int size)
{
    for (int i=1;i<size;i++)
    {
        for (int j=size-i-1;j>0;j--)
        {
            printf(" ");
        }
        for (int k=0;k<i;k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k=0;k<i;k++)
        {
            printf("#");
        }

        printf("\n");
    }
}