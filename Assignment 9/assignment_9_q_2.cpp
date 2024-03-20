#include<iostream>
#include<list>
using namespace std;

class Exception{
    string message;

    public:

    Exception(){
        this->message = "something went wrong";
    }
    Exception(string message){
        this->message = message;
    }

    string display(){
        return this->message;
    }
};

class insufficient_funds{
    int accid;
    double current_balance;
    double withdraw_amount;

    public:
    insufficient_funds(int accid, double current_balance, double withdraw_amount){
        this->accid = accid;
        this->current_balance = current_balance;
        this->withdraw_amount = withdraw_amount;
    }

    void display(){
        cout<<"Insufficient Funds"<<endl;
        cout<<"Account Number: "<<accid<<endl;
        cout<<"Current Balance: "<<current_balance<<" is insufficient"<<endl;
        cout<<"Withdraw Amount: "<<withdraw_amount<<endl;
    }
};

enum account_type {
    SAVING,
    CURRENT,
    DMAT
};

class Account{
    int id;
    double balance;
    account_type type;

    public:
    Account(){
        id = 0;
        balance = 0;
        type = SAVING;
    }

    Account(int id, account_type type){
        this->id = id;
        this->type = type;
    }

    void accept(){
        cout<<"enter account id: ";
        int x;
        cin >> x;
        set_id(x);

        cout<<"enter account type: 0 - for savings, 1 - for current, 2 - for dmat"<<endl;
        cin >> x;
        set_type((account_type)x);

        cout << "enter account balance: ";
        cin>>balance;

    }

    void display(){

        cout<<"Account Number: "<<id<<endl;
        cout<<"Account Type: "<<(type == 0 ? "saving" : type==1 ? "current" : "dmat")<<endl;
        cout<<"Account Balance: "<<balance<<endl;
    }

    void set_id(int id){
        if(id<0)
            throw Exception("id cannot be negative");

        this->id = id;
    }

    void set_type(account_type type){
        this->type = type;
    }

    int get_id(){
        return this->id;
    }

    int get_type(){
        return this->type;
    }
    double get_balance(){
        return this->balance;
    }

    void deposit(double amount){
        this->balance += amount;
    }

    void withdraw(double amount){
        if(amount > this->balance)
            throw insufficient_funds(this->id, this->balance, amount);

        this->balance -= amount;
    }

};

int menu(){
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. display Account info\n";
    cout << "5. display all acounts\n";
    cin >> choice;
    return choice;
}

int main(){
    int choice = 0;
    list<Account> accounts;
    list<Account>::iterator it = accounts.begin();

    while(choice=menu()){
        try
        {
            switch(choice){
                case 1:{
                    Account acc;
                    acc.accept();
                    accounts.push_back(acc);
                    break;
                }
                case 2:{
                    int id;
                    cout << "Enter account id : ";
                    cin >> id;
                    list<Account>::iterator ptr=accounts.end();
                    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
                        if(it->get_id()==id)
                            ptr = it;
                    }
                    if(ptr==accounts.end()){
                        cout << "Account not found! \n";
                        break;
                    }
                    double amount;
                    cout << "enter deposit amount : ";
                    cin >> amount;
                    ptr->deposit(amount);
                    cout << '\n';
                    cout << "Your updated account balance : " << ptr->get_balance() << '\n';
                    break;
                }
                case 3:{
                    int id;
                    cout << "Enter account id : ";
                    cin >> id;
                    list<Account>::iterator ptr=accounts.end();
                    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
                        if(it->get_id()==id)
                            ptr = it;
                    }
                    if(ptr==accounts.end()){
                        cout << "Account not found! \n";
                        break;
                    }
                    double amount;
                    cout << "enter withdraw amount : ";
                    cin >> amount;
                    ptr->withdraw(amount);
                    cout << '\n';
                    cout << "Your updated account balance : " << ptr->get_balance() << '\n';
                    break;
                }
                case 4:{
                    int id;
                    cout << "Enter account id : ";
                    cin >> id;
                    list<Account>::iterator ptr=accounts.end();
                    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
                        if(it->get_id()==id)
                            ptr = it;
                    }
                    if(ptr==accounts.end()){
                        cout << "Account not found! \n";
                        break;
                    }
                    ptr->display();
                    break;
                }
                case 5:{
                    cout << "All accounts \n";
                    list<Account>::iterator ptr = accounts.end();
                    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
                        it->display();
                        cout << "\n";
                    }
                    break;
                }
                default:
                    cout<<"Invalid choice\n";
            }
        }
        catch(Exception &error){
            cout << error.display() << '\n';
        }
        catch(insufficient_funds &error){
            error.display();
        }
    }
    cout << "Thank you ...\n";
}