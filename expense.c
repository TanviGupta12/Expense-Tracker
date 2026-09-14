#include <stdio.h>

void addExpense() {
    struct Expense e;

    printf("Enter day month year:(dd mm yyyy) ");
    scanf("%d %d %d", &e.day, &e.month, &e.year);

    printf("Enter amount(Rs.): ");
    scanf("%f", &e.amount);

    printf("Enter category: ");
    scanf("%s", e.category);

    e.userIndex = currentUserIndex;
    expenses[expenseCount++] = e;

    printf("Expense added!\n");
}

void viewMonthlyExpenses() {
    printf("Enter month and year(mm yyyy): ");   
    int m, y,c=0;
    scanf("%d %d", &m, &y);
    printf("\n--- Your Expenses in %02d/%d ---\n", m, y);

    for (int i = 0; i < expenseCount; i++) {
        c++;
        if (expenses[i].userIndex == currentUserIndex && expenses[i].month == m && 
            expenses[i].year == y) {
            printf("%02d/%02d/%d | Rs. %.2f | %s\n",
                   expenses[i].day,
                   expenses[i].month,
                   expenses[i].year,
                   expenses[i].amount,
                   expenses[i].category);
        }
    }
    if (c==0){
        printf("No expenses found for this month and year.\n");
    }
}

void viewYearlyExpenses() {
  printf("Enter year: ");   
    int y,c=0;
    scanf("%d",&y);
    printf("\n--- Your Expenses in %d ---\n", y);

    for (int i = 0; i < expenseCount; i++) {
        c++;
        if (expenses[i].userIndex == currentUserIndex && expenses[i].year == y) {
            printf("%02d/%02d/%d | Rs. %.2f | %s\n",
                   expenses[i].day,
                   expenses[i].month,
                   expenses[i].year,
                   expenses[i].amount,
                   expenses[i].category);
        }
    }
    if (c==0){
        printf("No expenses found for this year.\n");
    }
}
