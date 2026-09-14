#include <stdio.h>
#include <stdlib.h>
#include "data.c"
#include "user.c"
#include "expense.c"
#include "report.c"
int main() {
    loadData(); 
    int choice, auth = 0;

    while (!auth) {
        while(1){
        printf("\n--- WELCOME TO EXPENSE TRACKER ---\n");
        printf("\n1. Login\n2. Signup\n3. Exit\nChoice: ");
       if( scanf("%d", &choice)==1){break;}
       else{
        printf("Invalid input! Please enter a number.\n");
        while(getchar()!='\n');
        }}
        switch (choice) {
            case 1:
                auth = login();
                if (!auth)
                    printf("Invalid login!\n");
                break;
            case 2:
                signup();
                break;
            case 3:
                saveData();
                return 0;   
            default:
                printf("Invalid choice!\n");
        }
    }
   while (1) {
     while (getchar() != '\n');
    printf("\n--- MENU ---\n");
    printf("1. Add Expense\n2. View Monthly Expenses\n3. View Yearly Expenses\n4. Monthly Report\n");
    printf("5. Annual Report\n6. Add Income(monthly)\n7. Savings(monthly)\n8. Exit\n");

    char input[10];
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &choice) != 1) {
        printf("Invalid choice!\n");
        continue;
    }

    switch (choice) {
        case 1: addExpense(); break;
        case 2: viewMonthlyExpenses(); break;
        case 3: viewYearlyExpenses(); break;
        case 4: monthlyReport(); break;
        case 5: annualReport(); break;
        case 6: addIncome(currentUserIndex); break;
        case 7: calculateSavings(currentUserIndex); break;
        case 8:
            saveData();
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
    }
}
    }
