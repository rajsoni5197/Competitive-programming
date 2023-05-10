#include<iostream>
using namespace std ;
int size = 100001;
int LPFS[100001];

void createLPFS()
{
    for(int i = 0 ; i < size ; i++) LPFS[i] = i ;
    
    for(int i= 2 ;i*i <= size ; i++)
    {
        if(LPFS[i] == i)
        {
            for(int j = i*i ; j< size ; j+=i)
            {
               if(LPFS[j] == j) LPFS[j] = i;
            } 
        }
    }
}

int main()
{
    
    createLPFS();
    for(int i = 2 ; i< 100001 ; i++)
    {
        int n = i;
        cout<<n<<": ";
        while(n != 1)
        {
            cout<<LPFS[n]<<" ";
            if(LPFS[n]!= 0)
            n /= LPFS[n];
        }
        cout<<endl;
    }
    return 0;
}