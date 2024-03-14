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
    Employee(int id, float salary)
    {
        this->id = id;
        this->salary = salary;
    }

    // getters
    int getId()
    {
        return id;
    }
    float getSalary()
    {
        return salary;
    }

    // setters
    void setId(int id)
    {
        this->id = id;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }

    // accept function
    virtual void acceptdata()
    {
        cout << "Enter the id:- ";
        cin >> id;
        cout << "Enter the Salary:- ";
        cin >> salary;
    }

    // display function
    virtual void displayData()
    {
        cout << "Id is : " << id << endl;
        cout << "Salary is : " << salary << endl;
    }
    virtual ~Employee()
    {
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

protected:
    void acceptManager()
    {
        // Employee::acceptdata();
        cout << "Enter the bonus:- ";
        cin >> bonus;
    }
    void displayManager()
    {
        // Employee::displayData();
        cout << "Bonus is " << bonus << endl;
    }

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

    // accept function
    void acceptdata()
    {
        Employee::acceptdata();
        acceptManager();
    }

    // display function
    void displayData()
    {
        Employee::displayData();
        displayManager();
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

protected:
    void acceptSalesman()
    {
        // Employee::acceptdata();
        cout << "Enter the commition:- ";
        cin >> comm;
    }

    void displaySalesman()
    {
        // Employee::displayData();
        cout << "The commition is:- " << comm << endl;
    }

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

    // accept function
    void acceptdata()
    {
        Employee::acceptdata();
        acceptSalesman();
    }

    // display function
    void displayData()
    {
        Employee::displayData();
        displaySalesman();
    }
};

class Sales_manager : public Manager, public Salesman
{
public:
    Sales_manager() {}
    Sales_manager(int id, double sal, double bonus, double comm)
    {
        setId(id);
        setSalary(sal);
        setBonus(bonus);
        setComm(comm);
    }

    void acceptdata()
    {
        Employee::acceptdata();
        acceptManager();
        acceptSalesman();
    }

    // display function
    void displayData()
    {
        Employee::displayData();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    int size;
    int count = 0;
    cout << " Enter Employee count : ";
    cin >> size;
    Employee *eptr[size];

    int choice;

    do
    {
        cout << "-------------------------------------" << endl;
        cout << "         *MENU*               " << endl;
        cout << "-------------------------------------" << endl;
        cout << "0. EXIT" << endl;
        cout << "1. Add Manager" << endl;
        cout << "2. Add Salesman" << endl;
        cout << "3. Add Sales Manager" << endl;
        cout << "4. Display Manager" << endl;
        cout << "5. Display Salesman" << endl;
        cout << "6. Display Sales Manager" << endl;
        cout << "Enter your choice - ";
        cin >> choice;

        switch (choice)
        {
            {
            case 0:
                cout << "Thank you......!" << endl;
                break;
            }
        case 1:
        {
            cout << "-----------Enter the detais for Manager-----------" << endl;
            if (count < size)
            {
                eptr[count] = new Manager();
                eptr[count]->acceptdata();
                count++;
            }
            else
            {
                cout << "Employee limit is exceeded.... " << endl;
            }
            break;
        }
        case 2:
        {
            cout << "-----------Enter the detais for Salesman-----------" << endl;
            if (count < size)
            {
                eptr[count] = new Salesman();
                eptr[count]->acceptdata();
                count++;
            }
            else
            {
                cout << "Employee limit is exceeded.... " << endl;
            }

            break;
        }
        case 3:
        {
            cout << "-----------Enter the detais for Sales Manager-----------" << endl;
            if (count < size)
            {
                eptr[count] = new Sales_manager();
                eptr[count]->acceptdata();
                count++;
            }
            else
            {
                cout << "Employee limit is exceeded.... " << endl;
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < count; i++)
            {
                if (typeid(*eptr[i]) == typeid(Manager))
                {
                    cout << "---------Here are detais for employee----------" << endl;
                    eptr[i]->displayData();
                    cout << " --------------------- " << endl;
                }
            }
            break;
        }
        case 5:
        {
            for (int i = 0; i < count; i++)
            {
                if (typeid(*eptr[i]) == typeid(Salesman))
                {
                    cout << "---------Here are detais for Salesman----------" << endl;
                    eptr[i]->displayData();
                    cout << " --------------------- " << endl;
                }
            }
            break;
        }
        case 6:
        {
            for (int i = 0; i < count; i++)
            {
                if (typeid(*eptr[i]) == typeid(Sales_manager))
                {
                    cout << "---------Here are detais for Sales Manager----------" << endl;
                    eptr[i]->displayData();
                    cout << " --------------------- " << endl;
                }
            }
            break;
        }
        default:

            cout << "Invalid valid choice......." << endl;
            break;
        }
    } while (choice != 0);

    for (int i = 0; i < size; i++)
    {
        delete eptr[i];
        eptr[i] = NULL;
    }

    return 0;
}