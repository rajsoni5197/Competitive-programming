#include<iostream>
using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int n ,i,f=1, res=0;
        cin>>n>>i;
        f = f<<i;
        res = f&n ;
        if(res) printf("The %dth bit of %d is %d",i,n,1);
        else printf("The %dth bit of %d is %d",i,n,0);
        cout<<endl;
    }
    return 0; 
}