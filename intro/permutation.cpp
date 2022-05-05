#include<iostream>
using namespace std;
int main()
{
    long long n,i;
    cin>>n;
    if(n==2||n==3)
    {
    cout<<"NO SOLUTION";
    }
    else if(n%2==0)
    {
        for(i=2;i<=n;i+=2)
        cout<<i<<" ";
        for(i=1;i<n;i+=2)
        cout<<i<<" ";
    }
    else
    {
        for(i=2;i<n;i+=2)
        cout<<i<<" ";
        for(i=1;i<=n;i+=2)
        cout<<i<<" ";

    }
    return 0;
}