#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for (int j=low;j<high;j++){
        if (arr[j]<pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high){
    if (low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void main(){
    int n;
    printf("read array limit");
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        printf("read element %d",i);
        scanf("%d",&a[i]);
    }

    quickSort(a,0,n-1);

    printf("sorted array\n");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}