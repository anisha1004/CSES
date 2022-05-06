#include<iostream>
#include<vector>
using namespace std;

int mod=1e9+7;
int solve(vector<int>& coins, int tar,  vector<int>& v)
{
    if(tar==0) 
        return 1;
    if(tar<0)
        return 0;
    if(v[tar]!=-1)
        return v[tar];
    int ans=0;
    for(int i=0; i<coins.size(); ++i)
    {
        (ans+=solve(coins, tar-coins[i], v))%=mod;
    }
    v[tar]=ans;
    return v[tar];
}
int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; ++i)
        cin>>coins[i];
    vector<int> v(x+1, -1);
    cout<<solve(coins, x, v);
    return 0;
}