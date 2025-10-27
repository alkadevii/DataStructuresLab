#include<stdio.h>

void readPolynomial(int a[][2],int n){
    for (int i=0;i<n;i++){
        printf("enter the coefficient");
        scanf("%d",&a[i][0]);
        printf("enter the exponent");
        scanf("%d",&a[i][1]);
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

int addPolynomials(int a[][2],int b[][2],int c[][2],int n1,int n2){
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

    while(j<n2){
        c[k][0]=b[j][0];
        c[k][1]=b[j][1];
        j++;
        k++;
    }

    return k;
}

void main(){
    int n1,n2;

    printf("enter number of non-zero elements in polynomial A");
    scanf("%d",&n1);
    int a[n1][2];
    readPolynomial(a,n1);

    printf("enter number of non-zero elements in polynomial B");
    scanf("%d",&n2);
    int b[n2][2];
    readPolynomial(b,n2);

    printf("The polynomials are:\n");
    printf("polynomial A ");
    printPolynomial(a,n1);
    printf("polynomial 2 ");
    printPolynomial(b,n2);

    int r[n1+n2][2];

    int n3=addPolynomials(a,b,r,n1,n2);

    printf("The sum of the polynomials is:\n");
    printPolynomial(r,n3);
}