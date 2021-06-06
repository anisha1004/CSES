#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,k,i,j,c=0;
    cin>>n>>m>>k;
    long long a[n],b[m];
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<m;++i)
    cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    i=0;
    j=0;
    while(i<n && j<m)
    {
        if(abs(a[i]-b[j])<=k)
        {
            i++;
            j++;
            c++;
        }
        else
        {
            if(a[i]-b[j]>k)
            j++;
            else
            i++;
        }
    }
    cout<<c;
    return 0;
}