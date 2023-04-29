#include<iostream>
using namespace std ;

class Sieve
{public:
    int n;
    bool* sieve;
    Sieve(int n)
    {
        sieve = new bool[n+1];
        sieve[0] = sieve[1]= 0;
        for(int i= 2 ; i< n;i++ )
        {
            sieve[i] = 1; 
        }
        for(int i = 2 ; i*i< n ; i++ )
        {
            if(sieve[i] == 1)
            {
                for(int j = i*i ; j<= n ; j+=i)
                {
                    sieve[j] = 0;
                }
            }
        }
    }
    bool isPrime(int n)
    {
        return sieve[n];
    }
};
int main()
{
    int testCase , input;
    cin>>testCase;
    Sieve seo(1e6);
    while (testCase--)
    {
       cin>>input;
       if(seo.isPrime(input))
        cout<<"YES"<<endl;
       else
        cout<<"NO"<<endl;
    }
    
}
