#include <stdio.h>
#include<iostream>
using namespace std;
void update(int *a,int *b) 
{     int tempa;
      int tempb;
      tempa = *a+*b;
      tempb = *a-*b;
      if (tempb < 0) 
      {
          tempb = tempb*(-1);
      }
      *a = tempa;
      *b = tempb;
}
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
