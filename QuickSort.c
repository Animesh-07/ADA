//QUICKSORT
#include <stdio.h>
#include <stdlib.h>

int comp=0;

void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void ascending(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
        a[i]=i+1;
}

void descending(int a[],int n)
{
    int i,j=0;
    for(i=n-1;i>=0;i--)
        a[j++]=i+1;
}

void random(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=rand()%1000;
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

int partition(int a[],int l,int r)
{
    int p,i,j;
    p=a[l];
    i=l+1;
    j=r;
    while(i<=j)
    {
        while(a[i]<p)
        {
            i++;
            comp++;
        }
        while(a[j]>p)
        {
            j--;
            comp++;
        }
        if(i<j)
            swap(a[i],a[j]);
        else
           swap(a[l],a[j]);
    }
    return j;
}

void quicksort(int a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
}

int main()
{
    int choice,n,a[100];
    while(1)
    {
        printf("----------Quick sort---------\n");
        printf("\nEnter your choice of array element:\n\n1.Ascending order\n2.Descending order\n3.Random order\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the size of the array:\n");
                    scanf("%d",&n);
                    ascending(a,n);
                    printf("\nThe ascending elements are:\n");
                    display(a,n);
                    quicksort(a,0,n-1);
                    printf("\nSORTED ARRAY:\n");
                    display(a,n);
                    printf("\n\nNo. of comparisons: %d\n",comp);
                    break;
             case 2:printf("\nEnter the size of the array:\n");
                    scanf("%d",&n);
                    descending(a,n);
                    printf("\nThe ascending elements are:\n");
                    display(a,n);
                    quicksort(a,0,n-1);
                    printf("\nSORTED ARRAY:\n");
                    display(a,n);
                    printf("\n\nNo. of comparisons: %d\n",comp);
                     break;
             case 3:printf("\nEnter the size of the array:\n");
                    scanf("%d",&n);
                    random(a,n);
                    printf("\nThe ascending elements are:\n");
                    display(a,n);
                    quicksort(a,0,n-1);
                    printf("\nSORTED ARRAY:\n");
                    display(a,n);
                    printf("\n\nNo. of comparisons: %d\n",comp);
                     break;
            case 4: printf("GOODBYE!\n");
                     exit(0);
            default: printf("\nINVALID CHOICE\n\n");

        }
    }
}

