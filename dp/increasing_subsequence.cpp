#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve_dp(vector<int>& v, int n)
{
    vector<int> dp(n, 1);
    for(int i=1; i<n; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            if(v[i]>v[j] && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int solve(vector<int>& v, int n, int ind, int mx)
{
    if(ind==n)
        return 0;
    int in=0, ex=0;
    if(mx<v[ind])
        in=solve(v, n, ind+1, v[ind])+1;
    ex=solve(v, n, ind+1, mx);
    return max(in, ex);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    cout<<solve_dp(v, n);
    return 0;
}