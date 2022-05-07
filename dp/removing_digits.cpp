#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
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

int solve(int m)
{
    if(m==0)
        return 0;
    int ans=INT32_MAX;
    string s=to_string(m);
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]!='0')
            ans=min(ans, solve(m-s[i]+'0')+1);
    }
    return ans;
}
int main()
{
    int m, ans=0;
    cin>>m;
    //cout<<solve_greedy(m);
    cout<<solve(m);
    return 0;
}