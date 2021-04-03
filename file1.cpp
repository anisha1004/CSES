#include <iostream>
#include <algorithm>
using namespace std;
int main()
{   
    long long int n,sum=0;
    cin>>n;
    long long int i,a[n-1];
    for(i=0;i<n-1;++i)
    {
    cin>>a[i];
    sum+=a[i];
    }
    cout<<(n*(n+1)/2)-sum;
    return 0;
}