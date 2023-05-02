#include<iostream>
#include<vector>
using namespace std ;

vector<int>primes;
int sieveLength =90000001;
bool sieve[90000001];
void createSieve()
{
    
        sieve[0] = sieve[1]= 0;
       
        for(int i = 2 ; i< sieveLength;i++) sieve[i] =1;
        for(int i = 2 ; i*i< sieveLength ; i++ )
        {
            if(sieve[i] == 1)
            {
                for(long long j = i*i ; j<= sieveLength ; j+=i)
                {
                    sieve[j] = 0;
                }
            }
        }
}
void fillPrimes()
{
    for(long long i =0 ;i< sieveLength ; i++)
    {
        if(sieve[i])primes.push_back(i);
    }
}
int main()
{
    createSieve();
    fillPrimes();
    int testCount , k ;
    cin>>testCount;
    while(testCount--)
    {
        cin>>k;
        cout<<primes[k-1]<<endl;
    }
}