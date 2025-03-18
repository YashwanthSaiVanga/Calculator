Here’s a simple Bank Account System and Calendar System using Object-Oriented Programming (OOP) in C++. The implementation includes key features like deposits, withdrawals, and date navigation.


---

Option 1: Bank Account System

This program allows a user to deposit, withdraw, and check their balance.

Code:

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    // Constructor
    BankAccount(std::string name, double initial_balance) {
        owner = name;
        balance = initial_balance;
    }

    // Deposit Method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit Successful! New Balance: $" << balance << "\n";
        } else {
            std::cout << "Invalid Deposit Amount!\n";
        }
    }

    // Withdraw Method
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal Successful! New Balance: $" << balance << "\n";
        } else {
            std::cout << "Insufficient Funds or Invalid Amount!\n";
        }
    }

    // Display Balance
    void displayBalance() {
        std::cout << "Account Holder: " << owner << "\nBalance: $" << balance << "\n";
    }
};

int main() {
    // Create Account
    BankAccount account("John Doe", 1000.0);

    // Perform operations
    account.displayBalance();
    account.deposit(500);
    account.withdraw(200);
    account.displayBalance();

    return 0;
}

Features:

✔ Uses OOP principles (encapsulation, constructors).
✔ Implements deposit, withdraw, and display balance methods.
✔ Ensures valid transactions.


---

Option 2: Simple Calendar System

This program allows the user to navigate dates using OOP.

Code:

#include <iostream>

class Calendar {
private:
    int day, month, year;

public:
    // Constructor
    Calendar(int d, int m, int y) : day(d), month(m), year(y) {}

    // Display current date
    void showDate() {
        std::cout << "Current Date: " << day << "/" << month << "/" << year << "\n";
    }

    // Move to next day (basic version without leap year handling)
    void nextDay() {
        day++;
        if ((month == 2 && day > 28) || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || day > 31) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    // Move to previous day
    void previousDay() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = 30; // Simplified month handling
        }
    }
};

int main() {
    Calendar myCalendar(28, 2, 2024);

    myCalendar.showDate();
    myCalendar.nextDay();
    myCalendar.showDate();
    myCalendar.previousDay();
    myCalendar.showDate();

    return 0;
}

Features:

✔ Uses OOP principles (constructors, encapsulation).
✔ Implements basic date navigation.
✔ Handles month and year transitions.


---

Would you like additional features, such as interest calculation for the bank or full leap year support for the calendar?
