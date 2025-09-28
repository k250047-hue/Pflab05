#include <stdio.h>

int main(){
    int permistion_flag = 1 | 2 | 4 ; 
    if(permistion_flag & 4) printf("Access granted: Full control");
    else {
        if((permistion_flag & 3)==3) printf("Access granted : read and write");
        else if (permistion_flag & 1) printf("Access granted : read-only");
        else printf("Access denied");
    }
    return 0;
}