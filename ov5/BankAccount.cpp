#include "std_lib_facilities.h"
#include "BankAccount.h"


BankAccount::BankAccount() {}

void BankAccount::setBalance(int money) {
    balance = money;
}
int BankAccount::getBalance() {
    return balance;
}
void BankAccount::add(int money) {
    balance += money;
}
void BankAccount::subtract(int money) {
    balance -= money;
}

