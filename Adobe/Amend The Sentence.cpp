// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string amendSentence(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                ans += s[i];
            if (s[i] >= 'A' && s[i] <= 'Z')
                ans += (s[i] - 'A' + 'a');
            if (s[i + 1] >= 'A' && s[i + 1] <= 'Z')
                ans += " ";
        }
        if (s[s.size() - 1] >= 'A' && s[s.size() - 1] <= 'Z')
            ans += (s[s.size() - 1] - 'A' + 'a');
        else
            ans += s[s.size() - 1];
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.amendSentence(s) << endl;
    }
} // } Driver Code Ends