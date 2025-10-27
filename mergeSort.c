#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    for (int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    for (int j=0;j<n2;j++){
        r[j]=arr[mid+1+j];
    }

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if (l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }

    while (i<n2){
        arr[k]=r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if (left<right){
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
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

    mergeSort(a,0,n-1);

    printf("sorted array\n");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}