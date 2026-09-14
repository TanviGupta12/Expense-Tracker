# Expense Tracker

A console-based **Expense Tracker developed in C** to help users manage their personal finances through a simple command-line interface.

## Features

* User **Signup and Login**
* Add and store expenses with:
  * Date
  * Amount
  * Category
* View all recorded expenses
* Generate **monthly expense reports**
* Generate **annual expense reports**
* Add and track income
* Calculate **savings**
* Persistent data storage using **text files**
* Simple menu-driven console interface

## Technologies Used

* **C**
* **File Handling**
* Standard C Libraries
* Console-based Interface

## Data Files

The application uses text files to store data:

* `users.txt` — User login information
* `expenses.txt` — Expense records
* `income.txt` — Income records

## Project Purpose

This project was developed to practice **C programming concepts, functions, file handling, structures/data management, and menu-driven program design** while building a practical personal finance application.

## How to Run

Compile the program using a C compiler such as GCC:

```bash
gcc main.c -o expense_tracker
```

Then run:

```bash
./expense_tracker
```

On Windows:

```bash
expense_tracker.exe
```

## Future Improvements

* Expense category-wise analysis
* Budget setting and tracking
* Improved input validation
* Graphical reports
* Password security
* Export reports to CSV/PDF
