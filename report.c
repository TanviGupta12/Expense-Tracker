#include <stdio.h>
#include<string.h>
void monthlyReport() {
    int m, y;
    printf("Enter month and year(mm yyyy): ");
    scanf("%d %d", &m, &y);

    char categories[50][20];
    float totals[50] = {0};
    int catCount = 0;
    float grandTotal = 0;

    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].userIndex == currentUserIndex &&
            expenses[i].month == m &&
            expenses[i].year == y) {

            int found = -1;

            for (int j = 0; j < catCount; j++) {
                if (strcmp(categories[j], expenses[i].category) == 0) {
                    found = j;
                    break;
                }
            }

            if (found == -1) {
                strcpy(categories[catCount], expenses[i].category);
                totals[catCount] = expenses[i].amount;
                catCount++;
            } else {
                totals[found] += expenses[i].amount;
            }

            grandTotal += expenses[i].amount;
        }
    }

    if (catCount == 0) {
        printf("No expenses found.\n");
        return;
    }

    for (int i = 0; i < catCount - 1; i++) {
        for (int j = 0; j < catCount - i - 1; j++) {
            if (totals[j] < totals[j + 1]) {

                float temp = totals[j];
                totals[j] = totals[j + 1];
                totals[j + 1] = temp;

                char tempCat[20];
                strcpy(tempCat, categories[j]);
                strcpy(categories[j], categories[j + 1]);
                strcpy(categories[j + 1], tempCat);
            }
        }
    }

    printf("\n--- Monthly Report (%02d/%d) ---\n", m, y);

    for (int i = 0; i < catCount; i++) {
        printf("%s : Rs. %.2f\n", categories[i], totals[i]);
    }

    printf("-----------------------------\n");
    printf("Total = Rs. %.2f\n", grandTotal);
}
void annualReport() {
    int y;
    printf("Enter year: ");
    scanf("%d", &y);

    char categories[50][20];
    float totals[50] = {0};
    int catCount = 0;
    float grandTotal = 0;

    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].userIndex == currentUserIndex &&
            expenses[i].year == y) {

            int found = -1;

            for (int j = 0; j < catCount; j++) {
                if (strcmp(categories[j], expenses[i].category) == 0) {
                    found = j;
                    break;
                }
            }

            if (found == -1) {
                strcpy(categories[catCount], expenses[i].category);
                totals[catCount] = expenses[i].amount;
                catCount++;
            } else {
                totals[found] += expenses[i].amount;
            }

            grandTotal += expenses[i].amount;
        }
    }

    if (catCount == 0) {
        printf("No expenses found.\n");
        return;
    }

    for (int i = 0; i < catCount - 1; i++) {
        for (int j = 0; j < catCount - i - 1; j++) {
            if (totals[j] < totals[j + 1]) {

                float temp = totals[j];
                totals[j] = totals[j + 1];
                totals[j + 1] = temp;

                char tempCat[20];
                strcpy(tempCat, categories[j]);
                strcpy(categories[j], categories[j + 1]);
                strcpy(categories[j + 1], tempCat);
            }
        }
    }

    printf("\n--- Annual Report (%d) ---\n", y);

    for (int i = 0; i < catCount; i++) {
        printf("%s : Rs. %.2f\n", categories[i], totals[i]);
    }

    printf("-----------------------------\n");
    printf("Total = Rs. %.2f\n", grandTotal);
}

void addIncome(int currentUser) {
    struct Income in;

    printf("Enter month and year(mm yyyy): ");
    scanf("%d %d", &in.month, &in.year);

    printf("Enter income amount(Rs.): ");
    scanf("%f", &in.amount);

    in.userIndex = currentUser;

    incomes[incomeCount++] = in;

    printf("Income added successfully!\n");
}

float getMonthlyIncome(int user, int month, int year) {
    float total = 0;

    for (int i = 0; i < incomeCount; i++) {
        if (incomes[i].userIndex == user &&
            incomes[i].month == month &&
            incomes[i].year == year) {

            total += incomes[i].amount;
        }
    }

    return total;
}

float getMonthlyExpense(int user, int month, int year) {
    float total = 0;

    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].userIndex == user &&
            expenses[i].month == month &&
            expenses[i].year == year) {

            total += expenses[i].amount;
        }
    }

    return total;
}

void calculateSavings(int currentUser) {
    int month, year;

    printf("Enter month and year(mm yyyy): ");
    scanf("%d %d", &month, &year);

    float income = getMonthlyIncome(currentUser, month, year);
    float expense = getMonthlyExpense(currentUser, month, year);

    float savings = income - expense;

    printf("\n--- Savings Report ---\n");
    printf("Income: %.2f\n", income);
    printf("Expenses: %.2f\n", expense);
    printf("Savings: %.2f\n", savings);
}