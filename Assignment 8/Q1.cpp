#include<iostream>
using namespace std;

class Factorial
{
    private :
    int n,result;

    public:
    Factorial():n(0),result(1)
    {

    }

    Factorial(int n,int result)
    {
      this->n=n; 
      this->result=result; 
    }

    void fact()
    {   
        if(n<=0)
        {
        throw 1;
        }

        else 
        {
        
            for(int i=1 ; i<=n; i++)
            {
                result = result*i;
            }
        }
        
    }
    void acceptNumber()
    {
        cout<<"Eneter number to find factorial :";
        cin>>n;
    }

    void displayNumber()
    {
        cout<<"Factorial of "<<n<<" is "<<result<<endl;
    }



};
int main()
{   int a;
    Factorial f;
    f.acceptNumber();
    try
    {
        f.fact();
        f.displayNumber();
        
    }

    catch( int error)
    {
        cout<<"Number can not be less than zero.Please enter positive number "<<endl;
    }
 
 
    return 0;
}

