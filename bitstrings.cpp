#include<iostream>
using namespace std;
int main()
{
    long long i,n,c=1;
    cin>>n;
    for(i=0;i<n;++i)
    c*=2;
    cout<<c%(10^9+7);
    return 0;
}