#include <iostream>
using namespace std;

class Employee
{   
private:
    int id;
    float salary;


public:
    Employee()
    {
        id = 0;
        salary = 0.0;
    }
    Employee(int id,float salary)
    {
        this->id = id;
        this->salary = salary;
    }

    //getters
    int getId()
    {
        return id;
    }
    float getSalary()
    {
        return salary;
    }

    //setters
    void setId(int id)
    {
        this->id = id;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }

    //accept function
    virtual void acceptdata()
    {
        cout<<"Enter the id:- ";
        cin>>id;
        cout<<"Enter the Salary:- ";
        cin>>salary;
    }

    //display function
    virtual void displayData()
    {
        cout<<"Id is : "<<id<<endl;
        cout<<"Salary is : "<<salary<<endl;
    }
};

class Manager:virtual public Employee
{
private:
    float bonus;

public:

    Manager()
    {
        bonus = 0;
    }
    Manager(float bonus)
    {
        this->bonus = bonus;
    }
    float getBonus()
    {
        return bonus;
    }
    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }
    void acceptManager()
    {
        Employee::acceptdata();
        cout<<"Enter the bonus:- ";
        cin>>bonus;
    }
    void displayManager()
    {
        Employee::displayData();
        cout<<"Bonus is "<<bonus<<endl;
    }

};

class Salesman:virtual public Employee
{
protected:
    float comm;
public:
    Salesman()
    {
        comm = 0;
    }
    Salesman(float comm)
    {
        this->comm = comm;
    }

    float getComm()
    {
        return comm;
    }
    void setComm(float comm)
    {
        this->comm = comm;
    }

    void acceptSalesman()
    {
        Employee::acceptdata();
        cout<<"Enter the commition:- ";
        cin>>comm;
    }

    void displaySalesman()
    {
        Employee::displayData();
        cout<<"The commition is:- "<<comm<<endl;
    }
};

class Sales_manager:public Manager,public Salesman
{
public:
    Sales_manager()
    {

    }

    void acceptSales_manager()
    {
        Manager::acceptManager();
        cout<<"Enter the commition: ";
        cin>>comm;
        Salesman::setComm(comm);
    }

    void displaySales_manager()
    {
        Manager::displayManager();
        Salesman::getComm();
        cout<<"Commition is "<<comm;

    }
};


int main()
{
    Employee e1;
    
    

    Manager m1;
    
    

    Salesman s1;
    
    

    Sales_manager sm1;
    
    

    int choice;
do {
    cout<<"-------------------------------------"<<endl;
    cout<<"         *MENU*               "<<endl;
    cout<<"-------------------------------------"<<endl;
    cout << "0. EXIT" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Add Manager" << endl;
    cout << "3. Add Salesman" << endl;
    cout << "4. Add Sales Manager" << endl;
    cout << "5. Display Employee" << endl;
    cout << "6. Display Manager" << endl;
    cout << "7. Display Salesman" << endl;
    cout << "8. Display Sales Manager" << endl;
    cout << "Enter your choice - ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {cout<<"-----------Enter the detais for Employee-----------"<<endl;
    e1.acceptdata();
    break;}
    case 2:
       { cout<<"-----------Enter the detais for Manager-----------"<<endl;
        m1.acceptManager();
        break;}
    case 3:
        {cout<<"-----------Enter the detais for Salesman-----------"<<endl;
        s1.acceptSalesman();
        break;}
    case 4:
        {cout<<"-----------Enter the detais for Sales Manager-----------"<<endl;
        sm1.acceptSales_manager();
        break;}
    case 5:
        {cout<<"---------Here are detais for employee----------"<<endl;
        e1.displayData();
        break;}
    case 6:
        {cout<<"---------Here are detais for Manager----------"<<endl;
        m1.displayManager();
        break;}
    case 7:
        {cout<<"---------Here are detais for Salesman----------"<<endl;
        s1.displaySalesman();
        break;}
    case 8:
        {cout<<"---------Here are detais for Sales Manager----------"<<endl;
        sm1.displaySales_manager();
        break;}
    default:
        cout<<"Invalid valid choice......."<<endl;
        break;
    }
    }while(choice != 0);
    return 0;
}