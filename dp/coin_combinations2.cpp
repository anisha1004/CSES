#include<iostream>
#include<vector>
using namespace std;

int mod=1e9+7;
int solve(vector<int>& coins, int tar, int ind, vector<vector<int>>& v)
{
    if(tar==0)
        return 1;
    if(tar<0)
        return 0;
    if(v[ind][tar]!=-1)
        return v[ind][tar];
    int ans=0;
    for(int i=ind; i<coins.size(); ++i)
        (ans+=solve(coins, tar-coins[i], i, v))%=mod;
    v[ind][tar]=ans;
    return v[ind][tar];
}
int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; ++i)
        cin>>coins[i];
    vector<vector<int>> v(n+1, vector<int>(x+1, -1));
    v[0][0]=1;
    cout<<solve(coins, x, 0, v);
    return 0;
}
