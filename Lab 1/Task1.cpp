#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    BankAccount(const BankAccount& other) {
        balance = other.balance;
    }

    void deduct(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account1;
    cout << "Balance of account1 (default): $" << account1.getBalance() << endl;

    BankAccount account2(1000.0);
    cout << "Balance of account2 (initial balance): $" << account2.getBalance() << endl;

    BankAccount account3 = account2;
    cout << "Initial balance of account3 (copied from account2): $" << account3.getBalance() << endl;

    account3.deduct(200.0);
    cout << "Balance of account3 after deducting $200: $" << account3.getBalance() << endl;

    cout << "Balance of account2 after account3's transaction: $" << account2.getBalance() << endl;

    return 0;
}
