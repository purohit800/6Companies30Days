// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<string> remove_dup(vector<string> ans)
    {
        vector<string> v;
        v.push_back(ans[0]);
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] != ans[i - 1])
                v.push_back(ans[i]);
        }
        return v;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        string a = "";
        vector<string> temp;
        for (int i = 0; i < n; i++)
            temp.push_back(contact[i]);
        sort(temp.begin(), temp.end());
        temp = remove_dup(temp);
        for (int j = 0; j < s.size(); j++)
        {
            a += s[j];
            vector<string> v;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i].find(a) != string::npos)
                    v.push_back(temp[i]);
            }
            if (v.size() == 0)
            {
                v.push_back("0");
                ans.push_back(v);
            }
            else
                ans.push_back(v);
            temp = v;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends