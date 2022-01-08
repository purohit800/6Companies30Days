// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isnums(char a)
    {
        return a>='0' && a<='9';
    }
    string rec(string s,int &i,int &n)
    {
        int num=0;
        string ans="";
        for(;i<n;i++)
        {
            if(isnums(s[i]))
                num = 10*num + s[i]-'0';
            else if(s[i]=='[')
            {
                i++;
                string temp=rec(s,i,n);
                for(int j=0;j<num;j++)
                    ans+=temp;
                num=0;
            }
            else if(s[i]==']')
                return ans;
            else
                ans+=s[i];
        }
    }
    string decodedString(string s)
    {
        int i=0;
        int n=s.size();
        return rec(s,i,n);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends