#include<stdio.h>
void readSparseMatrix(int a[][3],int nonZero){
    for (int i=0;i<nonZero;i++){
        printf("enter row, col and value (in order)");
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
}

void printSparseMatrix(int a[][3],int nonZero){
    printf("Row Col Value\n");
    for (int i=0;i<nonZero;i++){
        printf("%d   %d   %d\n",a[i][0],a[i][1],a[i][2]);
    }           

}

void transposeSparse(int a[][3], int t[][3], int nonZero) {
    for (int i = 0; i < nonZero; i++) {
        t[i][0] = a[i][1]; 
        t[i][1] = a[i][0];
        t[i][2] = a[i][2];
    }
}

int addSparse(int a[][3],int b[][3],int c[][3],int n1,int n2){
    int i=0,j=0,k=0;
    while (i<n1 && j<n2){
        if (a[i][0]==b[j][0] && a[i][1]==b[j][1]){
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2]+b[j][2];
            i++;
            j++;
        }else if (a[i][0]<b[i][0] || a[i][0]==b[i][0] && a[i][1]<b[j][1]){
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2];
            i++;
        }else{
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            c[k][2]=b[j][2];
            j++;
        }
        k++;
    }

    while (i<n1){
        c[k][0]=a[i][0];
        c[k][1]=a[i][1];
        c[k][2]=a[i][2];
        i++;
        k++;
    }

    while (j<n2){
        c[k][0]=b[j][0];
        c[k][1]=b[j][1];
        c[k][2]=b[j][2];
        j++;
        k++;
    }

    return k;
}

void main() {
    int n1, n2;
    printf("Enter number of non-zero elements in matrix A: ");
    scanf("%d", &n1);
    int a[n1][3];
    readSparseMatrix(a, n1);

    printf("Enter number of non-zero elements in matrix B: ");
    scanf("%d", &n2);
    int b[n2][3];
    readSparseMatrix(b, n2);

    printf("\nMatrix A:\n");
    printSparseMatrix(a, n1);
    printf("\nMatrix B:\n");
    printSparseMatrix(b, n2);

    int c[n1 + n2][3];
    int n3 = addSparse(a, b, c, n1, n2);

    printf("\nSum of A and B:\n");
    printSparseMatrix(c, n3);

    int t[n1][3];
    transposeSparse(a, t, n1);
    printf("\nTranspose of A:\n");
    printSparseMatrix(t, n1);
}