#include <QtCore/QCoreApplication>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define size 10000

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
    clock_t start, end;
    int i;
    int second;
    int *arr = new int[size];
    for (i = 0; i < size; i++)
        arr[i] = rand()%20;
    //arrOut(arr);
    start = clock();
    selection(arr);
    end = clock();
    //arrOut(arr);
    second = end - start;
    printf ("%s\n%d", "The time of sort <Selection>:", second);
    getch();
}
