#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& h, vector<int> &s, int x, int ind)
{
    if(x<=0)
        return 0;
    int ans=INT32_MIN; 
    for(int i=ind; i<h.size(); ++i)
    {
        if(x-h[i]>=0)
            ans=max(ans, solve(h, s, x-h[i], i)+s[i]);
    }
    return ans;
}
int main()
{
    int  n, x;
    cin>>n>>x;
    vector<int> h(n);
    vector<int> s(n);
    for(int i=0; i<n; ++i)
        cin>>h[i];
    for(int i=0; i<n; ++i)
        cin>>s[i];
    cout<<solve(h, s, x, 0);
    return 0;
}