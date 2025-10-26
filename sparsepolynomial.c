#include<stdio.h>

void readPolynomial(int poly[][2],int n){
     for (int i=0;i<n;i++){
        printf("enter the coefficient");
        scanf("%d",&poly[i][0]);
        printf("enter the exponent");
        scanf("%d",&poly[i][1]);
     }
}

void printPolynomial(int poly[][2],int n){
    for (int i=0;i<n;i++){
        printf("%dx^%d ",poly[i][0],poly[i][1]);
        if (i!=n-1){
            printf("+");
        }
    }
}

int addPolynomials(int a[][2],int b[][2],int n1,int n2,int c[][2]){
    int i=0,j=0,k=0;
    while (i<n1 && j<n2){
        if (a[i][1]==b[j][1]){
            c[k][0]=a[i][0]+b[j][0];
            c[k][1]=a[i][1];
            i++;
            j++;
        }else if (a[i][1]>b[j][1]){
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            i++;
        }else{
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            j++;
        }
        k++;
    }
    while (i<n1){
        c[k][0]=a[i][0];
        c[k][1]=a[i][1];
        i++;
        k++;
    }
    while (j<n2){
        c[k][0]=b[j][0];
        c[k][1]=b[j][1];
        j++;
        k++;
    }

    return k;

}

void main(){
    int n1,n2;
    printf("enter number of non zero elements in polynomial 1");
    scanf("%d",&n1);

    int poly1[n1][2];
    readPolynomial(poly1,n1);

    printf("enter number of non zero elements in polynomial 2");
    scanf("%d",&n2);

    int poly2[n2][2];
    readPolynomial(poly2,n2);

    printf("The polynomials are:\n");
    printf("polynomial 1 ");
    printPolynomial(poly1,n1);
    printf("polynomial 2 ");
    printPolynomial(poly2,n2);

    int r[n1+n2][2];

    int n3=addPolynomials(poly1,poly2,n1,n2,r);

    printf("The sum of the polynomials is:\n");
    printPolynomial(r,n3);

    
}