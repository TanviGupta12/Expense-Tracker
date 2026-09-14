#include <stdio.h>
#include <stdlib.h>
#define MAX_USERS 50
#define MAX_EXPENSES 500
#define MAX_INCOMES 200

struct Income {
    int month;
    int year;
    float amount;
    int userIndex;
};


struct User {
    char username[20];
    char password[20];
};

struct Expense {
    int day, month, year;
    float amount;
    char category[20];
    int userIndex;
};

struct User *users;
struct Expense *expenses;
struct Income *incomes;
int incomeCount = 0;
int userCount = 0;
int expenseCount = 0;
int currentUserIndex = -1;

void loadData() {
FILE *f1,*f2,*f3;
  users=(struct User *)malloc(MAX_USERS * sizeof(struct User));
expenses=(struct Expense *)malloc(MAX_EXPENSES * sizeof(struct Expense));
incomes=(struct Income *)malloc(MAX_INCOMES * sizeof(struct Income));
if (users==NULL||expenses==NULL||incomes==NULL){
    printf("Memory allocation failed\n");
    exit(1);
}
f1=fopen("users.txt","r");
f2=fopen("expenses.txt","r");
f3 = fopen("income.txt", "r");
if (f1 == NULL || f2 == NULL||f3==NULL) {
        printf("Error opening file\n");
        exit(1);
    }
userCount=0;
while (userCount < MAX_USERS &&
           fscanf(f1, "%19s %19s",
                  users[userCount].username,
                  users[userCount].password
                  ) == 2) {
        userCount++;
    }
    fclose(f1);
    expenseCount = 0;
    while (expenseCount < MAX_EXPENSES &&
           fscanf(f2, "%d %d %d %f %19s %d",
    &expenses[expenseCount
    ].day,
    &expenses[expenseCount].month,
    &expenses[expenseCount].year,
    &expenses[expenseCount].amount,
    expenses[expenseCount].category,
    &expenses[expenseCount].userIndex) == 6) {
        expenseCount++;
    }
    fclose(f2);
    while (
        fscanf(f3, "%d %d %f %d",
        &incomes[incomeCount].month,
        &incomes[incomeCount].year,
        &incomes[incomeCount].amount,
        &incomes[incomeCount].userIndex) != EOF) {
        incomeCount++;
    }
    fclose(f3);
    printf("(Data loaded)\n");


}
void saveData() {
    FILE *f1 = fopen("users.txt", "w");
    FILE *f2 = fopen("expenses.txt", "w");
    FILE *f3 = fopen("income.txt", "w");
    if (f1 == NULL || f2 == NULL || f3 == NULL) {
        printf("Error saving data\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        fprintf(f1, "%s %s\n",
                users[i].username,
                users[i].password);
    }
    for (int i = 0; i < expenseCount; i++) {
 fprintf(f2, "%d %d %d %f %s %d\n",
    expenses[i].day,
    expenses[i].month,
    expenses[i].year,
    expenses[i].amount,
    expenses[i].category,
    expenses[i].userIndex);
    }


for (int i = 0; i < incomeCount; i++) {
    fprintf(f3, "%d %d %f %d\n",
        incomes[i].month,
        incomes[i].year,
        incomes[i].amount,
        incomes[i].userIndex);
}

    fclose(f3);
    fclose(f1);
    fclose(f2);
}