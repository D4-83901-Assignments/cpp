#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int trav;
    int size;

public:
    Stack() : Stack(5) {}

    Stack(int size)
    {

        cout << " ctor called " << size << endl;
        arr = new int[size];
        trav = -1;
        this->size = size;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isFull()
    {
        if (trav == (size - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (trav == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int n)
    {
        if (isFull())
        {

            cout << endl<< "Stack OverFlow..." << endl<< endl;
        }
        else
        {
            ++trav;
            arr[trav] = n;

            cout << endl<< " Pushed Successfully ....." << endl<< endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << endl<<"Stack UnderFlow ..." << endl<< endl;
        }
        else
        {

            cout << arr[trav] << " : Stack poped" << endl;
            arr[trav] = 0;
            trav--;
            cout <<endl<< " Poped Successfully .... " << endl<< endl;
        }
    }

    int peek()
    { 
        
        return arr[trav];
    }

    void print()
    {
        if (isEmpty())
        {
            cout << " Stack is Empty ......" << endl;
        }
        else
        {
            cout << "--------------------------------------" << endl;
            cout << " Printing the stack : " << endl;

            for (int i = trav; i >= 0; i--)
            {
                cout << " arr [ " << i << " ] : " << arr[i] << endl;
            }
            cout << "--------------------------------------" << endl;
        }
    }
};

enum EMenu
{
    EXIT,
    PUSH,
    POP,
    PEEK,
    ISEMPTY,
    ISFULL,
    PRINT
};

void menu()
{
    cout << "---------------  MENU -------------------" << endl;
    cout << "Enter Your Choice for STACK : " << endl;
    cout << " 0 : Exit " << endl;
    cout << " 1 : Push " << endl;
    cout << " 2 : Pop " << endl;
    cout << " 3 : Peek " << endl;
    cout << " 4 : Check Empty  " << endl;
    cout << " 5 : Check Full  " << endl;
}

int main()
{

    int choice;
    Stack s1;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case EXIT:
            cout << " Terminated ..." << endl;
            cout << " thank You ...." << endl;
            break;

        case PUSH:
        {
            cout << " Enter number you want to push : " << endl;
            int num;
            cin >> num;
            s1.push(num);

            break;
        }

        case POP:
        {
            s1.pop();
            break;
        }

        case PEEK:
        {
            if (s1.isEmpty())
            {
             cout << " Stack is Empty ......" << endl;
             cout << " Peek is not possible ...."<< endl << endl;
            }
            else{

             int num = s1.peek();
             cout << "peeked element is : " << num << endl<< endl;
            }
            break;
        }

        case ISEMPTY:
        {
            if (s1.isEmpty())
                cout  <<" Stack is empty ..." << endl;
            else
                cout << " Stack is not empty ..." << endl;

            break;
        }
        case ISFULL:
        {
            if (s1.isFull())
                cout << " Stack is FULL ..." << endl;
            else
                cout << " Stack is not FULL ..." << endl;

            break;
        }
        case PRINT:
            s1.print();
            break;

        default:
            cout << endl<< "Invalid Choice ..." << endl<<endl;
            break;
        }

    } while (choice != 0);

    return 0;
}