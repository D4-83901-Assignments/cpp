#include<iostream>
using namespace std;

class Date
{
    // Data Member
    private:
    int day;
    int month;
    int year;
    
    //MemberFunction
public:
void initDate()
{
    day = 25;
    month = 04;
    year = 1999;
}
void printDateOnConsole()
{
    cout<<"Date: "<<day << ":"<<month <<":"<<year;

}
void acceptDateFromConsole()
{
    cout<<"Enter the Date : ";
    cin>>day>>month>>year;

}
bool isLeapYear()
{
return (year % 4 == 0 || year % 400 == 0);   
}
};

int main()
{
    class Date d;
    int choice;
    do
    {
        
      
      cout<<"\n 0.Exit"<<endl;
      cout<<"1.init date"<<endl;
      cout<<"2.enter date"<<endl;
      cout<<"3.print date"<<endl;
      cout<<"Enter your choice ";
    cin>>choice; 
      
      

      switch (choice)
    {
    case 0:
        break;
    case 1:
    d.initDate();
    break;
    case 2 : 
    d.acceptDateFromConsole();
    break;
    case 3:
        d.printDateOnConsole();
        break;
    
    default:
    cout<<"Invalid choice"<<endl;
        break;
    }

    } while (choice );
    
}

