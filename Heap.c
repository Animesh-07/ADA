//HEAPSORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ascending(int arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
}
void descending(int arr[],int n)
{
    int i,j=0;
    for(i=n-1;i>=0;i--)
    {
        arr[j++]=i+1;
    }
}

void rndm(int arr[],int n)
{
    srand(time(NULL));
    int i;
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
}

void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void heapify1(int *arr,int n,int i)
{
    int maxm=i;
    int temp;
    int left= 2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[maxm])
        maxm=left;
    if(right<n && arr[right]>arr[maxm])
        maxm=right;
    if(maxm!=i)
    {
        //swap(arr[i],arr[maxm]);
        temp=arr[i];
        arr[i]=arr[maxm];
        arr[maxm]=temp;
        heapify1(arr,n,maxm);
    }
}

void heapsort1(int *arr,int n)
{
    int i,temp;
    for(i=n/2 -1 ; i>=0;i--)
        heapify1(arr,n,i);
    for(i=n-1;i>=0;i--)
    {
        //swap(arr[0],arr[i]);
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify1(arr,i,0);
    }
}

int main()
{
    int choice;
    int arr[1000];
    printf("\n--------------HEAPSORT PROGRAM---------------\n");
    while(1)
    {
        printf("\nGenerate elements in \n1.Ascending Order\n2.Descending Order\n3.Random Order\n4.Exit\nEnter your Choice\t");
        scanf("%d",&choice);
        int n;
        switch(choice)
        {
            case 1: printf("\nEnter the size of the array\n");
                     scanf("%d",&n);
                     ascending(arr,n);
                     printf("\nGenerated elements are\n");
                     display(arr,n);
                     heapsort1(arr,n);
                     printf("\nSorted Array:\n");
                     display(arr,n);
                     break;
            case 2: printf("\nEnter the size of the array\n");
                     scanf("%d",&n);
                     descending(arr,n);
                     printf("\nGenerated elements are\n");
                     display(arr,n);
                     heapsort1(arr,n);
                     printf("\nSorted Array:\n");
                     display(arr,n);
                     break;
            case 3: printf("\nEnter the size of the array\n");
                     scanf("%d",&n);
                     rndm(arr,n);
                     printf("\nGenerated elements are\n");
                     display(arr,n);
                     heapsort1(arr,n);
                     printf("\nSorted Array:\n");
                     display(arr,n);
                     break;
            case 4: printf("\nGOODBYE!\n");
                     exit(0);
            default:printf("Invalid choice/n");
        }
    }
}
