#include <stdio.h>
#include <stdlib.h>

int cmp=0;

void ascending(int arr[],int n)
{
    int i;
    printf("The array is\n");
    for(i=0;i<n;i++)
    {
         arr[i]=i+1;
         printf("%d\t",arr[i]);
    }
}
void descending(int arr[],int n)
{
    printf("The array is\n");
    int j=0,i;
    for(i=n;i>0;i--)
    {
        arr[j]=i;
        printf("%d\t",arr[j++]);
    }
}
void Random(int arr[],int n)
{
    int i;
    printf("The array is\n");
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%10000;
        printf("%d\t",arr[i]);
    }
}
void insertion(int *a,int n)
{
    int i,v,j;
    for(i=1;i<n;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v)
        {
            cmp++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }

}
int main()
{
    int a[20], n,i,ch1;
    printf("Enter no of elements to be sorted \n");
    scanf("%d",&n);
    printf("Enter\n1.Ascending array\n2.Descending order\n3.Random order\n4.Exit\n");
    scanf("%d",&ch1);
    if(ch1==1)
        ascending(a,n);
    else if(ch1==2)
        descending(a,n);
    else if(ch1==3)
        Random(a,n);
    else
        exit(0);
    insertion(a,n);
    printf("\nElements in sorted order is\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n\nNo of comparisons is: %d\n\n",cmp);
    return 0;
}
