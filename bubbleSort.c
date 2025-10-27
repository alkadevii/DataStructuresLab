#include<stdio.h>

void bubbleSort(int a[],int n){
    for (int i=0;i<n;i++){
       int flag=0;
       for (int j=0;j<n-1;j++){
        if (a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            flag=1;
        }
       }
       if (flag==0){
        break;
       }
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

    bubbleSort(a,n);

    printf("sorted array\n");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}