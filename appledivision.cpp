#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    long long n,i,j,t=0,m=INT32_MAX;
    cin>>n;
    long long a[n];
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        t+=a[i];
    }
    for(i=0;i<1<<n;++i)
    {
        long long s=0;
        for(j=0;j<n;++j)
        {
            if(i&1<<j)
            s+=a[j];
        }
        m=min(abs(t-2*s),m);
    }
    cout<<m;
    
    
    return 0;
}