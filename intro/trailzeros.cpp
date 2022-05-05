#include<iostream>
using namespace std;
int main()
{
    long long n,r,c=0;
    cin>>n;
    do
    {
        c+=n/5;
        r=n/5;
        n/=5;
    }while(r>5);
    cout<<c;
}