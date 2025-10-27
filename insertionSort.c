#include<stdio.h>

void insertionSort(int arr[],int n){
     for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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

    insertionSort(a,n);

    printf("sorted array\n");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}