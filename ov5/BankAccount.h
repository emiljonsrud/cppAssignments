#pragma once

class BankAccount {
private:
    int balance;

public:
    BankAccount();
    void setBalance(int money);
    int getBalance();
    void add(int money);
    void subtract(int money);



};