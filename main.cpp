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

void radix(int *ar, int *br, int *cr)
{
    int i,k,n;
    k = size;
    n = size;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
      {
         br[cr[ar[i]]-1]=ar[i];
         cr[ar[i]]-=1;
      }
}

int main()
{
    clock_t start1, start2, end1, end2;
    int i;
    int second1, second2;
    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *cr = new int[size];
    int *br = new int[size];
    for (i = 0; i < size; i++)
    {
        arr1[i] = rand()%20;
        arr2[i] = rand()%20;
    }
    //arrOut(arr1);
    start1 = clock();
    selection(arr1);
    end1 = clock();
    //arrOut(arr1);
    second1 = end1 - start1;
    printf ("%s\n%d\n", "The time of sort <Selection>:", second1);

    //arrOut(arr2);
    start2 = clock();
    radix(arr2, br, cr);
    end2 = clock();
    //arrOut(br);
    second2 = end2 - start2;
    printf ("%s\n%d\n", "The time of sort <Radix>:", second2);

    getch();
}
