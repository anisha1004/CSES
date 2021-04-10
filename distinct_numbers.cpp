#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,i,c=1;
    cin>>n;
    long long a[n];
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1;++i)
    {
        if(a[i]!=a[i+1])
        c++;
    }
    cout<<c;
    return 0;
}