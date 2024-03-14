// Write a menu driven program for Student management.
// In main(), create Array of Objects and provide facility for accept, print, search and sort.
// For student accept name, gender, rollNumber and marks of three subjects from user and print name,
// rollNumber, gender and percentage.
// Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
// sorting and searching array.
// Search function returns index of found Student, otherwise returns -1.

#include <iostream>
using namespace std;

// #define SIZE 3

class Student
{
private:
    string name;
    string gender;
    int rollNum;
    int m1;
    int m2;
    int m3;

public:
    Student() : Student("not set", "not set", 0, 0, 0, 0)
    {
    }

    Student(string name, string gender, int rollNum, int m1, int m2, int m3)
    {
        this->name = name;
        this->gender = gender;
        this->rollNum = rollNum;
        this->m1 = m1;
        this->m2 = m2;
        this->m3 = m3;
    }

    void displayStud()
    {
        cout << "----------------------------" << endl;
        cout << " stud Name is :" << name << endl;
        cout << "stud Roll Num is : " << rollNum << endl;
        cout << "stud Gender : " << gender << endl;
        float per = ((float)(m1 + m2 + m3) / 300) * 100;
        cout << "Gained Percentage : " << per << endl;
        cout << "----------------------------" << endl;
    }

    void acceptStud()
    {
        cout << endl;
        cout << "---------- Enter Student Info : ------------" << endl;
        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter Roll No : ";
        cin >> rollNum;

        cout << " Enter Gender :";
        cin >> gender;
        cout << " Enter marks for m1 :";
        cin >> m1;
        cout << " Enter marks for m2 :";
        cin >> m2;
        cout << " Enter marks for m3 :";
        cin >> m3;
        cout << endl;
        cout << "----------------------" << endl;
    }

    string getName()
    {
        return name;
    }

    int getRollNum()
    {
        return rollNum;
    }
};

int searchRecords(Student arr[], int SIZE)
{
    string strName;
    cout << " Enter Name you want to find : ";
    cin >> strName;
    for (int i = 0; i < SIZE; i++)
    {

        if (arr[i].getName() == strName)
        {
            return i;
        }
    }
    return -1;
}

void sortRecords(Student arr[], int SIZE)
{

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[i].getRollNum() > arr[j].getRollNum())
            {
                Student temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void menu()
{
    cout << " ----- Enter Your choice ---- " << endl;
    cout << " 1 : Print stuent Data : " << endl;
    cout << " 2 : Accept student Data : " << endl;
    cout << " 3 : Search Stuednt info using [ Name ]: " << endl;
    cout << " 4 : Sort student list using Roll Number  : " << endl;
}
enum EMENU
{
    EXIT,
    PRINT,
    ACCEPT,
    SEARCH,
    SORT
};

int main()
{
    int size;
    cout << " Enter Student Count : ";
    cin >> size;

    Student s1[size];
    int choice;
    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case EXIT:
            cout << " THANK YOU...." << endl;
            break;
        case PRINT:
        {
            for (int i = 0; i < size; i++)
            {
                s1[i].displayStud();
            }
            break;
        }
        case ACCEPT:
        {
            cout << " Enter " << size << " student data : " << endl;
            for (int i = 0; i < size; i++)
            {
                s1[i].acceptStud();
            }
            break;
        }
        case SEARCH:
        {
            int num = searchRecords(s1, size);
            if (num != -1)
            {
                cout << "----- Info Using Name : ----";
                s1[num].displayStud();
            }
            else
            {
                cout << "Student record not found for given name......." << endl
                     << endl;
            }
            break;
        }
        case SORT:
        {
            sortRecords(s1, size);
            cout << endl
                 << "------------ Sorted array Using Marks is -------" << endl
                 << endl;
            for (int i = 0; i < size; i++)
            {
                cout << " student "
                     << "[ " << i << " ]" << endl;
                s1[i].displayStud();
            }
            break;
        }
        default:
            cout << "Invalid Choice " << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}