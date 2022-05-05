#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t,k=1;
    cin>>t;
    while(t--)
    {
        int n,i;
        char c='A';
        cin>>n;
        int a[n];
        for(i=0;i<n;++i)
            cin>>a[i];
        vector<char> v;
        v.push_back(c);
        for(i=0;i<n-1;++i)
        {
            if(i%2==0)
            {
              if(a[i+1]<a[i])
              {
                while(a[i]--)
                {
                    c++;
                    v.push_back(c);
                }
                while(a[i+1]--)
                {
                    c--;
                    v.push_back(c);
                }
              }
              else
              {
                  
              }
            }
            
        }
        cout<<"Case #"<<k<<":"<<" ";
        for(i=0;i<v.size();++i)
        cout<<v[i];
        cout<<"\n";
        k++;
    } 
    return 0;
}