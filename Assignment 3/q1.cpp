#include<iostream>
using namespace std;

class Time
{
    private:
    int h;
    int m;
    int s;

    public:
    // Default constructor
    Time()
    {
        h = 10;
        m = 15;
        s = 22;
    }

    // Parameterized constructor
    Time(int hour, int minute, int second)
    {
        h = hour;
        m = minute;
        s = second;
    }

    void setHour(int hour)
    {
        h = hour;
    }

    void setMinute(int minute)
    {
        m = minute;
    }

    void setSecond(int second)
    {
        s = second;
    }

    int getHour()
    {
        return h;
    }

    int getMinute()
    {
        return m;
    }

    int getSecond()
    {
        return s;
    }

    void printTime()
    {
        cout << "The Current Time is: " << h << ":" << m << ":" << s << endl;
    }
};

int main()
{
    Time *arrptr = new Time[2];
    int choice;

    do {
        cout << "0. Exit\n";
        cout << "1. Enter time for object\n";
        cout << "2. Print all times\n";
      
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
              case 0: {
                cout << "Exiting...\n";
                break;
            }
            case 1: {
                // Enter time for each object
                for (int i = 0; i < 2; i++)
                {
                    cout << "Enter time for object " << i+1 << " (hh:mm:ss): ";
                    int hr, min, sec;
                    cin >> hr >> min >> sec;
                    arrptr[i] = Time(hr, min, sec);
                }
                break;
            }
            case 2: {
                // Printing all times
                for (int i = 0; i < 2; i++)
                {
                    cout << "Time for object " << i+1 << ": ";
                    arrptr[i].printTime();
                }
                break;
            }
          
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3);

    delete[] arrptr; 
    arrptr = NULL;
    return 0;
}
