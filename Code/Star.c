#include<stdio.h>
#include<conio.h>
void main()
{
    int n,m;
    printf("Enter the Row and column size :\n");
    scanf("%d %d",n,m);
    for (int i= 0; i <= n; i++)
    {
        for ( int k = 0; k <= m ; k++)
        {
            printf("*");
        }
        
        printf("\n");
    }
   // getch();
}