#include<stdio.h>

int main(){

    int age;
    printf("enter your age: ");
    scanf("%d",&age);

    if(age<5){
        printf("Ticket price:  free");
    }
    else if(age>5 && age<65){
        printf("Ticket price:  standard");
    }
    else 
        printf("Ticket price:  Discount");
    




    return 0;
}