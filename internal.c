#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void readMatrix(int rows,int cols,int matrix[rows][cols]){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

int convertToSparse(int rows,int cols,int matrix[rows][cols],int sparse[][3]){
    int k=0;
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if (matrix[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=matrix[i][j];
                k++;
            }
        }
    }
    return k;
}

void printSparseMatrix(int sparse[MAX][3], int nonZero) {
    printf("Row Col Value\n");
    for (int i = 0; i < nonZero; i++)
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

void transposeSparse(int sparse[][3],int transpose[][3],int nonzero){
    for (int i=0;i<nonzero;i++){
        transpose[i][0]=sparse[i][1];
        transpose[i][1]=sparse[i][0];
        transpose[i][2]=sparse[i][2];
    }
}

int addSparse(int A[][3],int B[][3],int C[][3],int n1,int n2){
    int i=0,j=0,k=0;
    while (i<n1 && j<n2){
        if (A[i][0]==B[j][0] && A[i][1]==B[j][1]){
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2]+B[j][2];
            i++;
            j++;
        }else if(A[i][0]<B[j][0] || A[i][0]==B[j][0] && A[i][1]<B[j][1]){
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2];
            i++;
        }else{
            C[k][0]=B[j][0];
            C[k][1]=B[j][1];
            C[k][2]=B[j][2];
            j++;
        }
        k++;
    }

     while (i < n1) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j < n2) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    return k;
}
void main(){
    int rows1,cols1,rows2,cols2;
    
    printf("Enter rows and cols of matrix A");
    scanf("%d %d",&rows1,&cols1);
    int A[rows1][cols1];
    printf("enter elements of Matrix A");
    readMatrix(rows1,cols1,A);

    printf("Enter rows and cols of matrix B");
    scanf("%d %d",&rows2,&cols2);
    int B[rows2][cols2];
    printf("enter elements of Matrix B");
    readMatrix(rows2,cols2,B);

    int sparseA[MAX][3],sparseB[MAX][3];
    int nA = convertToSparse(rows1, cols1, A, sparseA);
    int nB = convertToSparse(rows2, cols2, B, sparseB);

    printf("\nSparse Matrix A:\n");
    printSparseMatrix(sparseA, nA);
    printf("\nSparse Matrix B:\n");
    printSparseMatrix(sparseB, nB);

    int transposeA[MAX][3];
    transposeSparse(sparseA, transposeA, nA);
    printf("\nTranspose of A (Sparse):\n");
    printSparseMatrix(transposeA, nA);

    int sparseC[MAX][3];
    int nC=addSparse(sparseA,sparseB,sparseC,nA,nB);
    printf("Sum of A and B \n");
    printSparseMatrix(sparseC, nC);
}