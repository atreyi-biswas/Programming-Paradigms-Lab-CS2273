#include <iostream>
using namespace std;


class BankAccount{
private:
    int accNo;        //account number
    string name;      //account holder name
    double balance;   //account balance

public:
    BankAccount(int a, string n, double b){
        accNo = a;    //set acc no
        name = n;     //set name
        balance = b;  //set balance
    }

    friend class BankManager; //friend class
};

class BankManager{
private:
    static int totalAccounts; //count accounts

public:
    static void countAccount(){
        cout << "Total Accounts: " << totalAccounts << endl; //print count
    }

    static void addAccount(){
        totalAccounts++; //increase count
    }

    static void display(BankAccount &acc){
        cout << "Account No: " << acc.accNo << endl;
        cout << "Name: " << acc.name << endl;
        cout << "Balance: " << acc.balance << endl;
    }

    static bool hasSufficientBalance(BankAccount &acc, double amt){
        return acc.balance >= amt; // check balance
    }

    static void transfer(BankAccount &from, BankAccount &to, double amt){
        if(hasSufficientBalance(from, amt)){
            from.balance -= amt; // deduct
            to.balance += amt;   // add
            cout << "Transfer successful\n";
        }else{
            cout << "Insufficient balance\n";
        }
    }
};

int BankManager::totalAccounts = 0; //initialize to 0

int main(){

    int acc1, acc2;        //account numbers
    string name1, name2;   //names
    double bal1, bal2;     //balances
    double amount;         //transfer amount

    //user input
    cout << "Enter Account 1 details (accNo name balance): ";
    cin >> acc1 >> name1 >> bal1;

    cout << "Enter Account 2 details (accNo name balance): ";
    cin >> acc2 >> name2 >> bal2;

    //create objects
    BankAccount a1(acc1, name1, bal1);
    BankAccount a2(acc2, name2, bal2);

    BankManager::addAccount(); //count a1
    BankManager::addAccount(); //count a2

    BankManager::countAccount(); //show total

    cout << "\nAccount Details:\n";
    BankManager::display(a1); //show a1
    BankManager::display(a2); //show a2

    //transfer input
    cout << "\nEnter amount to transfer from Account 1 to Account 2: ";
    cin >> amount;

    BankManager::transfer(a1, a2, amount); //transfer money

    cout << "\nAfter Transfer:\n";
    BankManager::display(a1); //updated a1
    BankManager::display(a2); //updated a2

    return 0;
}