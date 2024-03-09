#include <iostream>
using namespace std;
class Tollboth
{
    private: 
    unsigned int totalNumberOfCars;
    double moneyCollected;
    public:
    Tollboth()
    {
        totalNumberOfCars = 0;
        moneyCollected = 0.0;
    }
    void payingcars()
    {
        totalNumberOfCars++;
        moneyCollected += 0.50;
    }
    void nopayingcars()
    {
        totalNumberOfCars ++;
    }
    void display() 
    {
        cout << "Total number of cars: " << totalNumberOfCars << endl;
        cout << "Total amount collected: " << moneyCollected << endl;
        cout << "Number of paying cars: " << totalNumberOfCars - 1 << endl;  
        cout << "Number of non-paying cars: 1" << endl; 
    }
};




int main()
{
    Tollboth toll;
        int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Car pays toll" << endl;
        cout << "2. Car doesn't pay toll" << endl;
        cout << "3. Display totals" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: \n";
        cin >> choice;

        switch (choice) {
            case 1:
                toll.payingcars();
                cout << "Car paid the toll.\n" << endl;
                break;
            case 2:
                toll.nopayingcars();
                cout << "Car didn't pay the toll.\n" << endl;
                break;
            case 3:
                toll.display();
                break;
            case 4:
                cout << "Sampla ki vishay\n" << endl;
                break;
            default:
                cout << "Invalid choice. Please choose again.\n" << endl;
        }
    } while (choice != 4);

    return 0;
}

