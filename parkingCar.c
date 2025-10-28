#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct car{
    char model[20];
    char licenseNo[10];
    struct car* link;
}car;

car* createnode(){
    car* carnode=(car*)malloc(sizeof(car));
    carnode->link=NULL;
    return carnode;
}

void insertLast(car* head,char model[],char licenseNo[]){
    car* carnode=createnode();
    strcpy(carnode->model,model);
    strcpy(carnode->licenseNo,licenseNo);
    if (head->link==NULL){
        head->link=carnode;
    }else{
        car* current=head->link;
        while (current->link!=NULL){
            current=current->link;
        }current->link=carnode;
    }
    carnode->link=NULL;
}

car* deleteLast(car* head){
    if (head->link==NULL){
        printf("No car in the parking lot");
    }else{
    car* prev=NULL;
    car* current=head->link;
    while (current->link!=NULL){
        prev=current;
        current=current->link;
    }
    prev->link=NULL;
    return current;
}
}

void push(car* head,char model[],char licenseNo[]){
    insertLast(head,model,licenseNo);
    printf("Car with license number %s parked successfully\n",licenseNo);
}

void pop(car* head){
    car* deletedCar=deleteLast(head);
    printf("Car with license number %s exited the parking lot\n",deletedCar->licenseNo);
}

void display(car* head){
    if (head->link==NULL){
        printf("No cars in the parking lot\n");
    }else{
        car* current=head->link;
        printf("Cars in the parking lot:\n");
        while (current!=NULL){
            printf("Model: %s, License No: %s\n",current->model,current->licenseNo);
            current=current->link;
        }
    }
}

void main(){
    int ch;
    char model[20],licenseNo[20];
    car* head=createnode();
    printf("Parking Lot Management System\n");
    while(1){
        printf("1.Park Car\n");
        printf("2.Exit Car\n");
        printf("3.Display Cars\n");
        printf("4.Exit System\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    printf("enter car model: ");
                    scanf("%s",model);
                    printf("enter license number: ");
                    scanf("%s",licenseNo);
                    push(head,model,licenseNo);
                    break;
            case 2:
                    pop(head);
                    break;         
            case 3:
                    display(head);
                    break;
            case 4: 
                    exit(0);
                    break;  
            default:
                    printf("Invalid choice\n");
        }
    }

}