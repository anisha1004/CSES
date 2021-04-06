#include<iostream>
using namespace std;
int main()
{
    long long n,i,c=0,d;
    cin>>n;
    long long a[n];
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n-1;++i)
    {
        if(a[i+1]<a[i])
        {
        d=a[i]-a[i+1];
        c+=d;
        a[i+1]+=d;
        }
    }
    cout<<c;
    return 0;
}