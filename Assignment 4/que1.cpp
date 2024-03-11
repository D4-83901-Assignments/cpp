#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2000;
    }
    Date (int day, int month, int year)
    {
        this -> day;
        this -> month;
        this -> year;
    }
    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
    void displayDate()
    {
        
        cout<<" "<<day<<"/"<<month<<"/"<<year<<endl;
    }
    void acceptDate()
    {
        
        cout << "Enter the day : "<<endl;
        cin >> day;
        cout<<"Enter the month : "<<endl;
        cin >> month;
        cout<<"Enter the year : "<<endl;
        cin >> year;
    }

    bool isLeapYear()
    {
        if ((year % 4 == 0 || year % 400 == 0)==1)
        {
        cout<<"The year is leap year"<<endl;
        return true;
        }
        else
        {
        cout << "The year is not a leap year" <<endl;
        return false;
        }
    }
};

class Person
{
private:
    string name;
    string address;
    Date bday;

public:

    Person ()
    {
        string name = " ";
        string address = " ";
    }
    Person(string name, string address)
    {
        this->name = name;
        this->address = address;
        
    }
    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    Date getBday()
    {
        return this->bday;
    }
    void setName(string n)
    {
        name = n;
    }
    void setAddress(string a)
    {
        address = a;
    }
    void setBday(Date d)
    {
        this -> bday = d;
    }
    void acceptPerson()
    {  cout<<endl<< "------ Enter personal info ---------"<<endl;
            cout<<"Enter name : ";
            cin>>name;
            cout<<"Enter Address : ";
            cin>>address;
            cout << "----------------------------------"<<endl;
            cout<<"Enter your birthdate: "<<endl;
            bday.acceptDate();
            cout << "----------------------------------"<<endl;
    }
    void displayPerson()
    {   cout << "\n----------------------------------"<<endl;
        cout<<"\n*Name is : "<<name<<endl;
        cout<<"*Address is : "<<address<<endl;
        cout << "----------------------------------"<<endl;
        cout << "*Date of birth is : \n";
        bday.displayDate();
    }

};

class Employee:public Person
{
private:  
    int emp_id;
    double salary;
    string department;
    Date doj;
public:
    Employee()
    {
        emp_id = 0;
        salary = 0.0;
        department = "";
        
    }
    int get_empId()
    {
        return emp_id;
    }
    double get_salary()
    {
        return salary;
    }
    string get_department()
    {
        return department;
    }
    Date get_doj()
    {
        return doj;
    }

    void set_empId(int id)
    {
            emp_id = id;
    }
    void set_salary(double sal)
    {
            salary = sal;
    }
    void set_Department(string dept)
    {
            department = dept;
    }
    void set_doj(Date date)
    {
            doj = date;
    }
    void acceptEmployee()
    {

        cout << "------------Please enter information of employee----------"<< endl;
        cout<<"Enter Employee Id : ";
        cin>>emp_id;
        cout<<"Enter Salary : ";
        cin>>salary;
        cout<<"Enter Department : ";
        cin>>department;
        cout<<"-----------------------------------------"<<endl;
        this->acceptPerson();
        cout<<"Enter your date of joining: "<<endl;
        doj.acceptDate();
    }
    void displayEmployee()
    {
        cout<<"\n*Employee Id : "<<emp_id;
        cout<<"\n*Salary : "<<salary;
        cout<<"\n*Department : "<<department;
        this->displayPerson();
        cout<<"-----------------------------------------"<<endl;
        cout<<"For date of joining: "<<endl;
        doj.displayDate();
        //te();
    }

};


int main()
{
    Employee e1;
    e1.acceptEmployee();

    cout<<"------printing all the information-------"<<endl;
    e1.displayEmployee();

}