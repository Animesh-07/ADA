//MERGESORT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[20],b[20];

void merge(int low,int mid,int high)
{
    int l1,l2,i;
    for(l1=low,l2=mid+1,i=low;l1<=mid && l2<=high;i++)
    {
        if(a[l1]<=a[l2])
            b[i]=a[l1++];
        else
            b[i]=a[l2++];
    }
    while(l1<=mid)
        b[i++]=a[l1++];
    while(l2<=high)
        b[i++]=a[l2++];
    for(i=low;i<=high;i++)
        a[i]=b[i];
}

void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
    else
        return;
}

int main()
{
    int i,j,n;
    printf("Enter the size :\t");
    scanf("%d",&n);
    printf("\nElements to be sorted :\t");
    for(j=0;j<n;j++)
        scanf("%d",&a[j]);
    printf("\n\nList before Sorting :\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    mergesort(0,n-1);
    printf("\n\nList after Sorting :\t");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
    return 0;
}



/*#include <stdio.h>
#include <stdlib.h>

int comp=0;

void merge(int *b,int *c,int *a,int p,int q)
{
    int i,j,k;
    i=0;j=0;k=0;
    while(i<p && j<q)
    {
        comp++;
        if(b[i]<c[j])
        {
            a[k]=b[i];
            i=i+1;
        }
        else
        {
            a[k]=c[j];
            j=j+1;
        }
        k=k+1;
    }
    if(i==p)
    {
        while(j<q)
        {
            a[k++]=c[j];
            j++;
        }
    }
    else
    {
        while(i<p)
        {
            a[k++]=b[i];
            i++;
        }
    }
}
void mergesort(int *a,int n)
{
    int b[200],c[200],i=0,j;
    if(n>1)
    {
        for(i=0;(i<n/2);i++)
        {
            b[i]=a[i];
        }
        int k=i;
        for(j=(n/2),i=0;j<n;j++,i++)
        {
            c[i]=a[j];
        }
        mergesort(b,k);
        mergesort(c,i);
        merge(b,c,a,k,i);
    }
}
void display(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",i);
    }
}
void ascending(int *a,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
}
void descending(int *a,int n)
{
    int i,j=0;
    for(i=n-1;i>=0;i--)
    {
        a[j++]=i-1;
    }
}
void random1(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
    }
}
int main()
{
    int a[500],n,choice;
    while(1)
    {
       printf("\nEnter the type of input \n\n1.Ascending\n2.Descending\n3.Random\n4.Exit\n\n");
       scanf("%d",&choice);
       switch(choice)
       {
            case 1: printf("\nEnter the size of the array:\n");
                    scanf("%d",&n);
                    ascending(a,n);
                    printf("\nElements of the array are:\n");
                    display(a,n);
                    mergesort(a,n);
                    printf("\n\nElements in sorted order:\n");
                    display(a,n);
                    printf("\n\nNo. of comparisons are: %d\n",comp);
                    break;
            case 2: printf("\nEnter the size of the array:\n");
                    scanf("%d",&n);
                    descending(a,n);
                    printf("\nElements of the array are:\n");
                    display(a,n);
                    mergesort(a,n);
                    printf("\n\nElements in sorted order:\n");
                    display(a,n);
                    printf("\n\nNo. of comparisons are: %d\n",comp);
                    break;
            case 3: printf("\nEnter the size of the array:\n");
                    scanf("%d",&n);
                    random1(a,n);
                    printf("\nElements of the array are:\n");
                    display(a,n);
                    mergesort(a,n);
                    printf("\n\nElements in sorted order:\n");
                    display(a,n);
                    printf("\n\nNo. of comparisons are: %d\n",comp);
                    break;
            case 4: printf("\nGoodbye!\n\n");
                    exit(1);
            default: printf("\n\ninvalid choice\n\n");
       }
    }
    printf("\n\n");
    return 0;
}*/
