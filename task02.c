#include<stdio.h>

int main(){

    int power ;
    char lightcolor;
    printf("enter power: ");
    scanf("%d",&power);
   
    if(power == 1){
        printf("enter lightcolor: ");
        scanf(" %c",&lightcolor);
    
    if(lightcolor == 'R'){
        printf("Stop");
    }
    else if(lightcolor == 'Y'){
        printf("Caution");
    }
    else if(lightcolor == 'G'){
        printf("Go");
    }
}
    else 
        printf("Off");
    


  return 0;

}