#include <iostream>
using namespace std;

namespace NStudent
{
    class student
    {
    private:
        int rollNo;
        string name;
        int marks;

    public:
        student()
        {
            rollNo= 0;
            name = "";
            marks = 0;
        }

        void initStudent()
        {
            rollNo=0;
            name = "";
            marks = 0;
        }

        student(int rollno, string n, int b)
        {
            this->rollNo = rollNo;
            this->name = name;
            this->marks = marks;
        }
        void displayStudent() const
        {
            cout << "---------------------------------" << endl;
            cout << "Student roll number:" << rollNo << endl;
            cout << "Student name :" << name << endl;
            cout << "Student marks :" << marks << endl;
            cout << "----------------------------------" << endl;

        }

        void acceptStudent()
        {
            cout << "Enter student roll no";
            cin >> rollNo;
            cout << "Enter student name";
            cin >> name;
            cout << "Enter student marks;";
            cin >> marks;
        }
    };
}

// using namespace NStudent;
int main()
{
    NStudent::student s;
    int choice;
    do
    {
        cout << "\n 0.Exit" << endl;
        cout << "\n 1.initStudent" << endl;
        cout << "\n 2.Enter Student info" << endl;
        cout << "\n 3.Print Student info" << endl;
        cout << "\n .Enter your choice" << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout<<"Thank You";
            break;
        case 1:
            // student s;
            s.initStudent();
            break;

        case 2:
            s.acceptStudent();
            break;

        case 3:
            s.displayStudent();
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice);
    return 0;
}