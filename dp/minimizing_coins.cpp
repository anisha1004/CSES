#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long solve(int x, vector<int>& coins, vector<long long>& v)
{
    if(v[x]!=-1) return v[x];
    if(x==0) return 0;
    long long count=INT32_MAX;
    for(int i=0; i<coins.size(); ++i)
    {
        if(x-coins[i]>=0)
        {
            count=min(count, solve(x-coins[i], coins, v)+1);
        }
    }
    v[x]=count;
    return v[x];
}
int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; ++i)
        cin>>coins[i];
    vector<long long> v(x+1, -1);
    long long ans=solve(x, coins, v);
    if(ans==INT32_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}