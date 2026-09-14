#include <stdio.h>
#include <string.h>
int isUsernameExists(char username[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0)
            return 1;
    }
    return 0;
}
int signup() {
    char username[20], password[20];

    printf("Enter username: ");
    scanf("%s", username);

    if (isUsernameExists(username)) {
        printf("Username already exists!\n");
        return 0;
    }
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);

    userCount++;
    printf("Signup successful!\n");
    return 1;
}
int login() {
    char username[20], password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {

            currentUserIndex = i;
            printf("Login successful!\n");
            return 1;
        }
    }

    return 0;
}