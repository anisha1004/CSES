#include<iostream>
#include<>
using namespace std;
int main()
{
    long long i,n,c=1;
    cin>>n;
    for(i=0;i<n;++i)
    c=(c*2)%(1000000007);
    cout<<c;
    return 0;
}