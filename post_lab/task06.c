#include <stdio.h>

int main(){

    char room, action;
    printf("Select the room : Living Room (L) or Kitchen(K) :\n");
    scanf("%c", &room);
    if (room != 'L' && room != 'K')
    {
        printf("Invalid room input ");
        return 0;
    }
    getchar();
    printf("Select the action : Lights (L) or Thermostat(T) :\n");
    scanf("%c", &action);
    if (action != 'L' && action != 'T'){
        printf("Invalid action input ");
        return 0;
    }

    switch (room){
        case 'L':{
            switch (action){
            case 'L':
                printf("Adjusting ambient lighting.");
                break;
            default:
                printf("Setting living room temperature .");
                break;
            }
        break;
    }
    default:
        switch (action){
            case 'L':
                printf("Turning on bright task lighting.");
                break;
            default:
                printf("Setting Kitchen temperature");
                break;
            }
        break;
    }
}