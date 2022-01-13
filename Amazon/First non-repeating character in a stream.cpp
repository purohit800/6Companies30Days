// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        int hash[26];
        for (int i = 0; i < 26; i++)
            hash[i] = 0;
        queue<char> q;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
            if (hash[s[i] - 'a'] == 1)
                q.push(s[i]);
            while (hash[q.front() - 'a'] != 1 && !q.empty())
                q.pop();
            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends