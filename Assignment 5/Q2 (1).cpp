#include<iostream>
using namespace std;
class Product
{
    private:
        int id;
        string title;
        float price;

    public:
        Product():id(0),title("Not Given"),price(0)
        {

        }

        Product(int id, string tittle, float price)
        {
            this->id=id;
            this->title=title;
            this->price=price;
        }

        virtual void displayDetails()
        {
            cout<<"ID number is :"<<id<<endl;
            cout<<"Titile :"<<title<<endl;
            cout<<"Price :"<<price<<endl;
        }

        virtual void acceptDetails()
        {
            cout<<"Enetr ID number";
            cin>>id;
            cout<<"Enter title :";
            cin>>title;
            cout<<"Enetr Price :";
            cin>>price;
        }

        float getPrice()
        {
            return price;
        }

};

class Tape : public Product
{
    private :
        string artist;
        

    public :
        Tape(): artist("Null")
        {

        }
        
        Tape(string artist)
        {
                this->artist=artist;
        }


        void displayDetails()
        {
           cout<<"==========================="<<endl;
           Product::displayDetails(); 
           cout<<"Tape artist name :"<<artist<<endl;
           cout<<"==========================="<<endl; 
           
        }
        
        void acceptDetails()
        {
            cout<<"==========================="<<endl;
            Product::acceptDetails();
            cout<<"Enetr artist name :";
            cin>>artist;
            cout<<"==========================="<<endl;
        }

};

class Book:public Product
{
    private:
        string author;

    public:
    Book():author("Not Entered")
    {

    }

    Book( string author)
    {
        this ->author=author;
    }
     

    void displayDetails()
        {
            cout<<"==========================="<<endl;
            cout<<"Book  author name :"<<author<<endl;
            Product::displayDetails();
            cout<<"==========================="<<endl;
           
        }

        void acceptDetails()
        {
            cout<<"==========================="<<endl;
            Product::acceptDetails();
            cout<<"Enetr author name :";
            cin>>author;
            cout<<"==========================="<<endl;
        }
};

 float calculateFinalBill(Product* pro[])
{

        float total_bill = 0;
        float tape_total = 0;           
        float books_total = 0;

        for(int i=0;i<3;i++)
            {
            if(typeid(*pro[i])== typeid(Book))
            {
                books_total= books_total + pro[i]->getPrice();
                
            }   
            if(typeid(*pro[i])==typeid(Tape))
            {
                tape_total = tape_total + pro[i]->getPrice();
                
            }
                  
            }

            total_bill = (tape_total*0.95f )+ (books_total * 0.9f); 
            return total_bill;
}

int menu()
{
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Add Book :"<<endl;
    cout<<"2. Add Tape :"<<endl;
    cout<<"3. Display Book :"<<endl;
    cout<<"4. Display Tape :"<<endl;
    cout<<"5. Total price :"<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    int choice,count,i =0;
    Product *pro[3] ;

    while((choice = menu() )!=0)
    {
    switch(choice)
    {
        case 1 :
        if( count <3)
        {
            pro[count] = new Book;//upcastinhg
            pro[count]->acceptDetails();
            count++;
        }
        else
            cout<<"Cart is Full";
            break;

        case 2 :
        if(count < 3)
        {
            pro[count] = new Tape;//upcasting
            pro[count]->acceptDetails();
            count++;
        }
        else 
            cout<<"Cart is Full";
            break;

        case 3 :
            for( i=0 ; i<count; i++)
            {
                if(typeid(*pro[i])==typeid(Book))
                pro[i]->displayDetails();
            }
            break;

        case 4 :
            for( i=0 ; i<count; i++)
            {
                if(typeid(*pro[i])==typeid(Tape))
                pro[i]->displayDetails();
            }
            break;

        case 5 :
            cout<<"Total Billl :"<< calculateFinalBill(pro)<<endl;
             break;  

        default :
            cout<<"Invalid Choice"<<endl;

    };
    };
           

}