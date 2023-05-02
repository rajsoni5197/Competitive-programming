#include<iostream>
#include<vector>
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
        for(int i = 2 ;  i*i< n ; i++ )
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
void createSegSieve(vector<unsigned long long>& res, vector<int> &primes, unsigned long long l , unsigned long long r)
{
    res.clear();
    bool segSieve[(r-l)+1];
    for(int i = 0 ;i < (r-l)+1 ; i++)
    {  segSieve[i] =1;
     
    }
    for(auto pri : primes)
    {
        
        unsigned long long firstFactor = (l/pri)*pri;
        if(firstFactor<l) firstFactor += pri;
        if(firstFactor< (unsigned long long)pri*pri) firstFactor =( unsigned long long)pri* pri;

        for(unsigned long long i = firstFactor ; i<= r ; i+= pri)
        {
            segSieve[i-l] = 0;
        }
    }
   
    for(int i = 0 ; i< (r-l)+1 ; i++)
    {
        if(segSieve[i]) 
        { 
            res.push_back(i+l);
        }
    }

}
int main()
{
    Sieve soe(1e6);
    vector<int>primes;
    vector<unsigned long long>resPrime ;
    unsigned long long  l , r; 
    
    cin>>l>>r;
    for(int i = 2;i<= 1e6 ;i++)
    {
        if(soe.isPrime(i))
        {
            primes.push_back(i);
        }
    }
    createSegSieve(resPrime,primes,l,r);
    cout<<resPrime[0]<<"  "<<resPrime[resPrime.size()-1];
   
    return 0;

}