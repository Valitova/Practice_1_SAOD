#include <QtCore/QCoreApplication>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define size 10

void arrOut (int *ar)
{
    printf("\n%s\n", "Array:");
    for (int i = 0; i < size; i++)
        printf ("%d\t", ar[i]);
    printf("\n");
}

void selection(int *ar)
 {
     int i, j, max, nmax;
     for(i = 0; i < size-1; i++)
       {
         max=ar[i];
         nmax=i;
         for(j = i+1; j < size; j++)
           {
             if (ar[j]<max)
                {
                 max=ar[j];
                 nmax=j;
                 }
           }
          ar[nmax]=ar[i];
          ar[i]=max;
           }
  }

int main()
{
    int i;
    int *arr = new int[size];
    for (i = 0; i < size; i++)
        arr[i] = rand()%20;
    arrOut(arr);
    selection(arr);
    arrOut(arr);
    getch();
}
