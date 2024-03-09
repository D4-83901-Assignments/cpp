#include<iostream>
using namespace std;

class Student
{
    //data member 
    private:
    int rollno;
    string name;
    int marks;

    //Memberfunction
    public:
    void initStudent()
    {
        rollno = 83901;
        name = "Shreedhan";
        marks = 82; 
    }
    void printStudentOnConsole()
    {
        cout<<"roll no : \n"<<rollno << "\nname : \n" <<name <<"\nmarks : \n"<< marks;

    }
    void acceptStudentFromConsole()
    {
        cout<<"Enter roll no , name & marks : ";
        cin>>rollno>>name>>marks;
    }
};

int main()
{
    class Student s;
    int choice;
    do
    {
        cout<<"\n 0.Exit"<<endl;
        cout<<"\n 1.initStudent"<<endl;
        cout<<"\n 2.Enter Student info"<<endl;
        cout<<"\n 3.Print Student info"<<endl;
        cout<<"\n .Enter your choice"<<endl;

        cin>>choice;

        switch (choice)
        {
        case 0:
            break;
        case 1 : 
        s.initStudent();
        
        break;

        case 2 :
        s.acceptStudentFromConsole();
        break;

        case 3:
        s.printStudentOnConsole();
        break;

        default:
        cout<<"Invalid choice"<<endl;
            break;
        }
    }while(choice);
    
}