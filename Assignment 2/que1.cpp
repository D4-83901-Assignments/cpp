#include <iostream>
using namespace std;
class Box
{
    private:

        double length;
        double width;
        double height;

    public:
        
        Box(double l,double w,double h)
        {
            length = l;
            width = w;
            height = h;
        }
        void acceptdata()
        {
            cout<<"Enter Lenght of box: \n"<<endl;
            cin>>length;
            cout<<"Enter Width of box: \n"<<endl;
            cin>>width;
            cout<<"Enter height of box: \n"<<endl;
            cin>>height;
        }
        void displayvolume()
        {
            cout<<"the volume of the box is: \n"<<length * width * height<<endl;
        }
};

int main()
{
    Box b(1,1,1);
    int choice;
    while (choice !=3)
    {
    
        
        cout<<"1.Enter the Diamentions: \n"<<endl;
        cout<<"2.Calculate the volume of box: \n"<<endl;
        cout<<"3.Exit.\n"<<endl;
        cout<<"What do you want to do?\n"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            b.acceptdata();
            break;
        case 2:
            b.displayvolume();
            break;
        
        default:
            cout<<"\nEnter the valid option please so we can help you even better...!"<<endl;
            break;
        }
    }
    return 0;
}