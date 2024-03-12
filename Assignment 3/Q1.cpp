// Write a class for Time and provide the functionality

#include <iostream>
using namespace std;

class Time
{
private:
    int hr;
    int min;
    int sec;

public:
    // Constructor
    Time() : Time(0, 0, 0)
    {
    }
    Time(int hr, int min, int sec) : hr(hr), min(min), sec(sec)
    {
    }

    // Inspector

    int getHour()
    {
        return hr;
    }
    int getMinute()
    {
        return min;
    }
    int getSeconds()
    {
        return sec;
    }

    // Mutators
    void setHour(int hr)
    {
        this->hr = hr;
    }
    void setMinute(int min)
    {
        this->min = min;
    }
    void setSeconds(int sec)
    {
        this->sec = sec;
    }

    // Facilitator

    void acceptTime(){

        cout << "Enter Time : "<< endl;
        cin >> hr >> min>> sec;
        

    }

    void printTime()
    {
        cout << " ----------------------------------------" << endl;
        cout << "Time is = " << this->hr << " : " << this->min << " : " << this->sec  << endl;
        cout << " ----------------------------------------" << endl;
    }
};

int main()
{
    int size;
    cout << "Enter size of array you want : ";
    cin >> size; 

    Time *ptrTime=new Time[size];

    cout << "Enter " << size << "differnt times as input in format (hr min sec) :" << endl;
    for (int i = 0; i < size; i++)
    {
      ptrTime[i].acceptTime();
      ptrTime[i].printTime();        
    }


    cout <<endl<< " All Times that you entered : "<<endl;
    for (int i = 0; i < size; i++)
    {
      ptrTime[i].printTime();        
    }

        delete[] ptrTime;
        
    return 0;
}