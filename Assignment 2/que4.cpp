#include<iostream>
using namespace std;
class Address
{
    private:
    string building;
    string street;
    string city;
    int pin;

    public:
    //constructors
    Address() 
    {
        building = "RAJMOHAN";
        street = "near bus stop";
        city="Sangli";
        pin=416416;
    }

    //Mutator ->Setters
    void set_building(string buildingname)
    {
        building = buildingname;
    }

    void set_street(string streetname)
    {
        street = streetname;
    }

    void set_city(string cityname)
    {
        city = cityname;
    }

    void set_pin(int pincode)
    {
        pin = pincode;
    }

    // Inspectors -> getters
    
    string get_building()
    {
       return this->building;
    }

    string get_street()
    {
        return this->street;
    }

    string get_city()
    {
        return this->city;
    }

    int get_pin()
    {
        return pin;
    }

    //facilitators

    void displayAddress() const
    {
        cout << "building = "<<building << endl;
        cout << "street = "<<street << endl;
        cout << "city = "<<city << endl;
        cout << "pin = "<< pin << endl;
    }

    void acceptAddress()
    {
        cin>>building;
        cin>>street;
        cin>>city;
        cin>>pin;
    }

};

int main()
{
    Address a;
    a.displayAddress();

    a.set_building("HIGH MONT");
    a.set_street("Near Sunbeam");
    a.set_city("Pune");
    a.set_pin(410410);

    cout << "changed Address is : " <<a.get_building() << endl;
    cout << "changed Address is : " <<a.get_street() << endl;
    cout << "changed Address is : " <<a.get_city() << endl;
    cout << "changed Address is : " <<a.get_pin() << endl;

    
    return 0;

}