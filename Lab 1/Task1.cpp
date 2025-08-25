#include <iostream>

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
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account1;
    std::cout << "Balance of account1: $" << account1.getBalance() << std::endl;

    BankAccount account2(1000.0);
    std::cout << "Balance of account2: $" << account2.getBalance() << std::endl;

    BankAccount account3(account2);
    account3.deduct(200.0);

    std::cout << "Balance of account3 after transaction: $" << account3.getBalance() << std::endl;
    std::cout << "Balance of account2 (unaffected): $" << account2.getBalance() << std::endl;

    return 0;
}
