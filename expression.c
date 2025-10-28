#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 100

struct node{
    char data[20];
    struct node *lchild,*rchild;
};


struct node *st[max];
int top=-1;
char pf[max];

struct node *newnode(char *data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    strcpy(tmp->data, data);
    tmp->lchild = tmp->rchild = NULL;
    return tmp;
}


void push(struct node *tmp)
{
    st[++top]=tmp;
}

struct node * pop()
{
    return st[top--];
}

struct node *tree(char pf[])
{
    struct node *t, *t1, *t2;
    int i = 0;

    while (pf[i] != '\0') {
        if (isalnum(pf[i])) {        
            char operand[20];
            int j = 0;

            while (isalnum(pf[i])) { 
                operand[j++] = pf[i++];
            }
            operand[j] = '\0';

            t = newnode(operand);
            push(t);
        } else if (pf[i] == ' ') {   // CHANGED: skip spaces
            i++;
        } else {                     // Operator
            char op[2];
            op[0] = pf[i];
            op[1] = '\0';
            i++;

            t = newnode(op);
            t1 = pop();
            t2 = pop();
            t->rchild = t1;
            t->lchild = t2;
            push(t);
        }
    }

    return st[top];
}



void inorder(struct node *root)
{
    if(root!=NULL)
    {
        struct node *p=root;
        inorder(p->lchild);
        printf(" %s ",p->data);
        inorder(p->rchild);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        struct node *p=root;
        printf(" %s ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    int ch;
   printf("\nEnter the postfix expression (use spaces between operands and operators):\n");
   fgets(pf, sizeof(pf), stdin);
    pf[strcspn(pf, "\n")] = 0;
    struct node *root=tree(pf);
    while(1)
    {
        printf("\nThe choices are\n1.Infix Expression \n2.Prefix Expression\n3.Exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nThe infix expression is\n");
                inorder(root);
                break;
            }
            case 2:
            {
                printf("\nThe prefix expression is \n");
                preorder(root);
                break;
            }
            case 3:
            {
                printf("\nExiting the program");
                return 0;
            }
            default:
            {
                printf("\nEnter a valid choice");
            }
        }
    }
}