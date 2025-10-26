#include<stdio.h>

void sort(int a[],int n){
    for (int i=0;i<n;i++){
        int temp;
        int flag=0;
        for (int j=0;j<n-1;j++)
            if (a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }       
        if (flag==0){
            break;
        }
    }
}

int binarySearch(int a[],int l, int u,int key){
    while (l<=u){
        int mid=(l+u)/2;
        if (a[mid]==key){
            return mid;
        }else if (a[mid]<=key){
            l=mid+1;
        }else{
            u=mid-1;
        }
    }
    return -1;
}

void main(){
    int n;
    printf("enter number of elements");
    scanf("%d",&n);

    int a[n];

    for (int i=0;i<n;i++){
        printf("enter array element %d",i+1);
        scanf("%d",&a[i]);
    }

    sort(a,n);
    printf("sorted array");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    int key;
    printf("enter element to search");
    scanf("%d",&key);

    int result=binarySearch(a,0,n-1,key);
    if (result==-1){
        printf("element not found");
    }else {
        printf("%d found at index %d",key,result);
    }
}