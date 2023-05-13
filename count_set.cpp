#include <iostream>
using namespace std;

int bfa(int n) // time : O(size upto most signigicant bit) space :O(1)
{
    int count = 0, res = 0;
    while (n)
    {
        res = n & 1;
        if (res)
            count++;
        n = n >> 1;
    }
    return count;
}
int brianKernighanAlgorithm(int n)//time : O(no. of set bit) space:o(1)
{
    int count =0 ;
    while(n)
    {
        count++;
        n = n& n-1;
    }
    return count;
}
int main()
{
    int testcase;
    int n ;
    cin >> testcase;
    while (testcase--)
    {
        cin>>n;
        cout<<bfa(n)<<endl;
        cout<<brianKernighanAlgorithm(n)<<endl<<endl;
    }
}