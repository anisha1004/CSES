#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int solve_dp(int m)
{
    vector<int> dp(m+1, 1e9);
    dp[0]=0;
    for(int i=1; i<=m; ++i)
    {
        string s=to_string(i);
        for(int j=0; j<s.length(); ++j)
            dp[i]=min(dp[i], dp[i-s[j]+'0']+1);
    }
    return dp[m];
}
int solve_greedy(int m)
{
    int ans=0;
    while(m>0)
    {
        int mx=INT32_MIN, n=m;
        while(n>0)
        {
            mx=max(mx, n%10);
            n/=10;
        }
        m-=mx;
        ans++;
    }
    return ans;
}

int solve(int m, vector<int>& v)
{
    if(v[m]!=-1)
        return v[m];
    if(m==0)
        return 0;
    int ans=INT32_MAX;
    string s=to_string(m);
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]!='0')
            ans=min(ans, solve(m-s[i]+'0', v)+1);
    }
    v[m]=ans;
    return v[m];
}
int main()
{
    int m, ans=0;
    cin>>m;
    //cout<<solve_greedy(m);
    // vector<int> v(m+1, -1);
    // cout<<solve(m, v);
    cout<<solve_dp(m);
    return 0;
}