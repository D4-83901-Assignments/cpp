
#include <iostream>
#include <vector>
using namespace std;

enum account_type
{
    SAVING,
    CURRENT,
    DMAT
};

class Insufficient_funds
{
private:
    int id;
    double cur_balance;
    double withdraw_amount;

public:
    Insufficient_funds(int id, double cur_balance, double withdraw_amount)
    {
        this->id = id;
        this->cur_balance = cur_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void display()
    {
        cout << "Account ID : " << id << endl;
        cout << "Current balance : " << cur_balance << endl;
        cout << "The amount you want to withdraw " << withdraw_amount << endl;
        cout << "SORRY.... Insufficient funds" << endl;
    }
};

class Account
{
private:
    int id;
    account_type type;
    double balance;

public:
    Account()
    {
        this->id = 0;
        this->type = SAVING;
        this->balance = 0;
    }
    Account(int id, double balance, account_type type)
    {
        this->id = id;
        this->type = type;
        this->balance = balance;
    }
    void accept()
    {
        int choice = 1;
        cout << "Enter ID : " << endl;
        cin >> id;
        cout << "Enter balancec : " << endl;
        cin >> balance;
        cout << "Enter the type:" << endl;
        cout << "0. For Saving:" << endl;
        cout << "1. For Current " << endl;
        cout << "2. For DMAT:" << endl;
        cin >> choice;

        switch (choice)
        {
        case SAVING:
            type = type;
            break;
        case CURRENT:
            type = CURRENT;
            break;
        case DMAT:
            type = DMAT;
            break;
        default:
            cout << "Enter the valid option" << endl;
        }
    }
    void display()
    {
        cout << "ID : " << id << endl;
        cout << "Account Type : " << type << endl;
        cout << "Balance : " << balance << endl;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    int get_id()
    {
        return id;
    }
    void set_type(account_type type)
    {
        this->type = type;
    }
    account_type get_type()
    {
        return type;
    }

    void set_balance(double balance)
    {
        this->balance = balance;
    }

    double get_balance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        this->balance = this->balance + amount;
    }
    void withdraw(double amount)
    {
        if (this->balance < amount)
        {
            throw Insufficient_funds(id, balance, amount);
        }
        this->balance = this->balance - amount;
    }
};

void menu()
{
    cout << "0.Exit" << endl;
    cout << "1.accept" << endl;
    cout << "2.display" << endl;
    cout << "3.deposit" << endl;
    cout << "4.withdraw" << endl;
}

int main(int argc, char const *argv[])
{
    vector<Account *> acc_vector;

    Account *ptr = NULL;

    int choice = 1;
    int id;
    double amount;
    while (choice != 0)
    {
        menu();
        cout << "Enter the choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Exiting" << endl;
            break;

        case 1:
            ptr = new Account;
            ptr->accept();
            acc_vector.push_back(ptr);
            break;

        case 2:
            for (int i = 0; i < acc_vector.size(); i++)
            {
                acc_vector[i]->display();
            }
            break;

        case 3:
            cout << "Enter Id:" << endl;
            cin >> id;
            for (int i = 0; i < acc_vector.size(); i++)
            {
                if (acc_vector[i]->get_id() == id)
                {
                    cout << "Enter Amount to deposit" << endl;
                    cin >> amount;
                    acc_vector[i]->deposit(amount);
                }
                else
                {
                    cout << "Worng ID" << endl;
                }
            }

            break;

        case 4:
            try
            {
                cout << "Enter Id:" << endl;
                cin >> id;
                for (int i = 0; i < acc_vector.size(); i++)
                {
                    if (acc_vector[i]->get_id() == id)
                    {
                        cout << "Enter Amount to Withdraw" << endl;
                        cin >> amount;
                        acc_vector[i]->withdraw(amount);
                    }
                    else
                    {
                        cout << "Worng ID" << endl;
                    }
                }
            }
            catch (Insufficient_funds e)
            {
                e.display();
            }

            break;

        default:
            break;
        }
    }

    return 0;
}
