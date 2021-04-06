#include<iostream>
using namespace std;
int main()
{
    long long n,i;
    cin>>n;
    if(n<=2)
    cout<<"NO SOLUTION";
    else if(n%2==0)
    {
        if((n/2)%2==0)
        {
            cout<<n/2<<"\n";
            for(i=1;i<=n/4;++i)
            cout<<i<<" ";
            for(i=n;i>3*n/4;--i)
            cout<<i<<" ";
            cout<<"\n"<<n/2<<"\n";
            for(i=n/4+1;i<=3*n/4;++i)
            cout<<i<<" ";
        }
        else
        cout<<"NO SOLUTION";
    }
    else
    {
        if((n*(n+1)/2)%2==0)
        {

        }
        else
        cout<<"NO SOLUTION";

    }
    return 0;
}