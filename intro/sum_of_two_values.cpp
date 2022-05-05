#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    long long n,x,i,j,c=0;
    cin>>n>>x;
    vector< pair <long long, long long> > v(n);
    for(i=0;i<n;++i)
    {
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    for(i=0,j=n-1;i<j;)
    {
        if(v[i].first+v[j].first>x)
        j--;
        if(v[i].first+v[j].first<x)
        i++;
        else 
        cout<<v[i].second<<" "<<v[j].second;
    }
    return 0;
}