#include <stdio.h>

int main()
{

    char username, password;
    printf("enter username: ");
    scanf("%c", &username);

    if (username == 'C')
    {
        printf("enter password: ");
        scanf(" %c",&password);

    if (password == 'C')
        {
            printf("login to the account");
        }
        else
            printf("Incorrect password");
    }
    else
        printf("Username not found");

    return 0;
}