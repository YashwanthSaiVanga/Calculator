#include <iostream>
#include <string>
using namespace std;

// Bank Account Class
class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }

    // Deposit Money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw Money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    // Display Account Balance
    void displayBalance() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

// Main Function
int main() {
    string name;
    double initialDeposit;

    // Get user details
    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter initial deposit amount: ";
    cin >> initialDeposit;

    // Create Account
    BankAccount account(name, initialDeposit);

    int choice;
    double amount;
    
    // Menu-driven system
    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayBalance();
                break;
            case 4:
                cout << "Thank you for using the bank system!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
