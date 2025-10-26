#include<stdio.h>
int binarysearch(int a[],int l,int u,int key){
    while(l<=u){
        int mid=(u+l)/2;
        if (a[mid]==key){
            return mid;
        }else if(a[mid]<key){
            l=mid+1;
        }else{
            u=mid-1;
        }
    }
    return -1;
}

void sort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void main(){
    int n;
    printf("enter limit for array");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        printf("read elements");
        scanf("%d",&arr[i]);
    }
    sort(arr, n);
    
    int key;
    printf("enter element to search");
    scanf("%d",&key);
    int result=binarysearch(arr,0,n-1,key);
    if (result==-1){
        printf("element not found");
    }else{
        printf("element found at %d",result);
    }
}