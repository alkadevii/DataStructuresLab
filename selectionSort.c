#include<stdio.h>

void selectionSort(int a[],int n){
    for (int i=0;i<n-1;i++){
        int min=i;
        for (int j=i+1;j<n;j++){
            if (a[j]<a[min]){
                min=j;
            }
        }

        if (min!=i){
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
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

    selectionSort(a,n);

    printf("sorted array\n");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}