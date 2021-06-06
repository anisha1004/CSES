#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,i,sum=0;
    cin>>n;
    long long p[n];
    for(i=0;i<n;++i)
    cin>>p[i];
    sort(p,p+n);
    for(i=0;i<n;++i)
    sum+=abs(p[i]-p[n/2]);
    cout<<sum;
    return 0;
}