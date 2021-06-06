#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,k=1;
    cin>>t;
    while(t--)
    {
        int n,i,c=1,sum=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;++i)
        cin>>a[i];
        sort(a,a+n);
        for(i=0;i<n;++i)
        {
            sum+=c;
            if(a[i+1]!=a[i])
              c++;
        }
        cout<<"Case #"<<k<<":"<<" "<<sum<<"\n";
        k++;
    } 
    return 0;
}