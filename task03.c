#include<stdio.h>

int main(){


int a,b,c,discriminant;
    printf("enter number1: ");
    scanf("%d",&a);
    printf("enter number2: ");
    scanf("%d",&b);
    printf("enter number3: ");
    scanf("%d",&c);

 discriminant = b*b  - 4*a*c;

if(discriminant>0){
    printf("two real roots");
}
else if(discriminant == 0){
    printf("one real root");
}
else if(discriminant<0){
    printf("Imaginary roots");
}
else ("invalid");


    return 0;
}