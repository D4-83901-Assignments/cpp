#include<iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 25;
        month = 04;
        year = 1999;
    }

    void printDateOnConsole()
    {
        cout<<"Date: "<<day << "/" << month << "/" << year;
    }

    void acceptDateFromConsole()
    {
        cout<<"Enter the Date : ";
        cin>>day>>month>>year;
    }

    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);   
    }
};

int main()
{
    Date d;
    int choice;
    do
    {
        cout<<"\n 0.Exit"<<endl;
        cout<<"1.Init date"<<endl;
        cout<<"2.Enter date"<<endl;
        cout<<"3.Print date"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice; 

        switch (choice)
        {
            case 0:
                break;
            case 1:
                d.initDate();
                break;
            case 2: 
                d.acceptDateFromConsole();
                break;
            case 3:
                d.printDateOnConsole();
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    } while (choice);
    
    return 0;
}


