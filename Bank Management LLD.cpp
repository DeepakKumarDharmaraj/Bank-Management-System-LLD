#include <iostream>
using namespace std;

//Console small project - bank mangement system

class Account{

    //memberdata
    protected:
    string Holder;
    double balance;

    public:
    //Constructor - intialize the protected data
    Account(string h,int b) : Holder(h),balance(b) {
        cout << Holder << " account created.\n";
    }

    //function overloading
    void deposit(int amt){
        balance += amt;
    }

    void deposit(double amt){
        balance += amt;
    }

    //abstraction
    virtual void withdraw(double amt) = 0;

    //Encapsultion - getter
    double getbalance(){
        return balance;
    }

    //destructor
    virtual ~Account(){
        cout << Holder << " account closed.";
    }

    friend void showdet(Account &a);
};

//friend function
void showdet(Account &a) {
    cout << "Account Holder:" << a.Holder << "\n" << "Account Balance:" << a.balance;
}

//Inheritance
class sa : public Account{
    public:
    sa(string h, double b) :  Account(h,b) {}

    //Polymorphism - runtime
    void withdraw(double amt) override{
        if(balance >= amt){
            balance -= amt;
        }
        else{
            cout << amt << " Invalid Amount!\n";
        }
    }
};

class money{
    public:
    int mt;
    money(int m) : mt(m) {}

    //Operator overloading
    money operator+(const money &m){
        return money(mt + m.mt);
    }
};

int main() {

    //object
    sa acc("Deepak",5000);

    //function overloading
    acc.deposit(100);
    acc.deposit(12.50);

    //Polymorphism
    Account* p = &acc;
    p -> withdraw(20000);

    //friend function
    showdet(acc);

    //Operator overloading
    money m1(200);
    money m2(300);

    money total = m1 + m2;

    cout << "\nTOTAL AMT:" << total.mt << endl;

    return 0;
}