#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeff;
    int exp;
    struct node* link;
}node;

node* createNode(){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->link=NULL;
    return newnode;
}

void insertLast(node* head,int coeff,int exp){
    node* newnode=createNode();
    newnode->coeff=coeff;
    newnode->exp=exp;
    if (head->link==NULL){
        head->link=newnode;
    }else{
        node* current=head->link;
        while (current->link!=NULL){
            current=current->link;
        }
        current->link=newnode;
    }
    newnode->link=NULL;
}

void display(node* head) {
    if (head->link== NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    node* current = head->link;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->link;
        if (current != NULL)
            printf(" + ");
    }
    printf("\n");
}

node* addPolynomial(node* head1,node* head2){
    node* result=createNode();
    node* p1=head1->link;
    node* p2=head2->link;

    while(p1!=NULL && p2!=NULL){
        if (p1->exp==p2->exp){
            insertLast(result,p1->coeff+p2->coeff,p1->exp);
            p1=p1->link;
            p2=p2->link;
        }else if(p1->exp>p2->exp){
            insertLast(result,p1->coeff,p1->exp);
            p1=p1->link;
        }else{
            insertLast(result,p2->coeff,p2->exp);
            p2=p2->link;
        }
    }
    while (p1!=NULL){
        insertLast(result,p1->coeff,p1->exp);
        p1=p1->link;
    }
    while (p2!=NULL){
        insertLast(result,p2->coeff,p2->exp);
        p2=p2->link;
    }

    return result;
}

void main(){
    node* head1=createNode();
    node* head2=createNode();
    int n1,n2;
    int coeff,exp;
    
    printf("enter number of elements in polynomial 1");
    scanf("%d",&n1);
    for (int i=0;i<n1;i++){
        printf("enter element");
        scanf("%d",&coeff);
        printf("enter exponent");
        scanf("%d",&exp);
        insertLast(head1,coeff,exp);
    }

    printf("enter number of elements in polynomial 1");
    scanf("%d",&n2);
    for (int i=0;i<n2;i++){
        printf("enter element");
        scanf("%d",&coeff);
        printf("enter exponent");
        scanf("%d",&exp);
        insertLast(head2,coeff,exp);
    }

    display(head1);
    display(head2);

    node* result=addPolynomial(head1,head2);
    display(result);
}