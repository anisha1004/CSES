#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>& g, vector<int>& vis, int node)
{
    vis[node]=1;
    for(int x: g[node])
    {
        if(!vis[x])
            dfs(g, vis, x);
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<int> vis(n+1, 0);
    vector<pair<int, int>> ans;
    for(int i=0; i<m; ++i)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1; i<n+1; ++i)
    {
        if(!vis[i])
        {
            ans.push_back({i-1,i});   //({1, i})
            dfs(g, vis, i);
        }
    }
    cout<<ans.size()-1<<"\n";
    for(int i=1; i<ans.size(); ++i)
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
}