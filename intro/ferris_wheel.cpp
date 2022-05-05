#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,i,j,x,c=0;
    cin>>n>>x;
    for(i=0;i<n;++i)
    sort(a,a+n);
    for(i=0,j=n-1;i<n,j>0;)
    {
        int sum=0,y=a[i]+a[j];
        if(a[i]+a[j]<x)
          i++;
        else
        y+=a[i+1];        
    }
    cout<<c;
    return 0;
}