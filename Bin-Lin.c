#include <stdio.h>
#include <stdlib.h>

int count=0;

void ascending(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=i+1;
}

void descending(int *a,int n)
{
    int i,j=0;
    for(i=n-1;i>=0;i--)
        a[j++]=i+1;
}

void Random(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=rand()%1000;
}

void display(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void bsort(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                //swap(a[j],a[j+1]);
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nsorted array is: \n");
    for(i=01;i<=n;i++)
       printf("%d\t",a[i]);
}

void binarySearch(int *a,int ele,int low,int high)
{
    int mid;
    if(low>high)
    {
        printf("\nELEMENT NOT FOUND");
        return;
    }
    mid=(low+high)/2;
    if(ele==a[mid])
    {
        count++;
        printf("\nNO. of comparisions is %d\n",count);
        printf("element found at position %d",mid+1);
        return;
    }
    else if(ele<a[mid])
    {
        count++;
        return(binarySearch(a,ele,low,mid-1));
    }
    else
    {
        count++;
        return(binarySearch(a,ele,mid+1,high));
    }
}

void linearSearch(int *a,int ele,int pos,int n)
{
    if(pos!=n)
    {
        if(a[pos]==ele)
        {
            count++;
            printf("\nNo. of comparison is: %d\n",count);
            printf("\nElement fount at position: %d\n",pos+1);
            return;
        }
        else
        {
            count++;
            pos++;
            return(linearSearch(a,ele,pos,n));
        }
    }
    else
    {
        printf("no. of comparison is: %d\n",count);
        printf("\nelement not found\n");
        return;
    }
    return;
}

int main()
{
    printf("\t\t**** Linear Binary ****\n\n");
    printf("\nEnter no. of elements :");
    int n,ele,ch,choice;
    scanf("%d",&n);
    int a[n];
    printf("\nInputs in :\n1.Ascending\n2.Descending\n3.Random\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: ascending(a,n);
                display(a,n);
                break;
        case 2: descending(a,n);
                display(a,n);
                break;
        case 3: Random(a,n);
                display(a,n);
                break;
    }
    printf("\nEnter\n1.Linear\n2.Binary\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nEnter element to be searched:\n");
        scanf("%d",&ele);
        linearSearch(a,ele,0,n);
    }
    else if(ch==2)
    {
        bsort(a,n);
        printf("\nEnter element to be searched:\n");
        scanf("%d",&ele);
        binarySearch(a,ele,0,n-1); //remember this
    }
    else
        printf("Not a valid input\n");
    return 0;
}
