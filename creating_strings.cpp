#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<string> v;
    while(next_permutation(s.begin(),s.end()))
        v.push_back(s);
    cout<<v.size()+1<<"\n";
    cout<<s<<"\n";
    for(string x:v)
    cout<<x<<"\n";
    return 0;

}