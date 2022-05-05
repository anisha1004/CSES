#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    long long i,c=1,m=1;
    cin>>s;
    for(i=0;i<s.length()-1;++i)
    {
        if(s[i]==s[i+1])
        {
            c++;
            m=max(m,c);
        }
        else
        c=1;
    }
    cout<<m;
    return 0;
}