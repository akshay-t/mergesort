#include <stdio.h>

void print(int a[]){
    int i;
    printf(" \n ");
    for(i=0;i<8;i++){
        printf(" %d ",a[i]);
    }
}

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int i,a1[n1],a2[n2];
    for(i=0;i<n1;i++)
        a1[i]=arr[l+i];
    for(i=0;i<n2;i++)
        a2[i]=arr[m+i+1];
    //print(a1);
    int k=l,j=0;
    i=0;    
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            arr[k]=a1[i];
            i++;
        }
        else{
            arr[k]=a2[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
        
}

void mergesort(int a[],int l,int r){
    if (l < r)
    {
         int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        
        merge(a,l,m,r);
    }
    
}



int main()
{   int a[8]={3,6,4,9,1,19,30,20};
    
    mergesort(a,0,7);
    int i;
    print(a);
    
    return 0;
}
