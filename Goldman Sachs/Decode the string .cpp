// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string printMinNumberForPattern(string str)
    {
        stack<int> s;
        int num = 1;
        string ans = "";
        for (char i : str)
        {
            if (i == 'D')
            {
                s.push(num);
                num++;
            }
            else
            {
                s.push(num);
                num++;
                while (!s.empty())
                {
                    ans += to_string(s.top());
                    s.pop();
                }
            }
        }
        s.push(num);
        while (!s.empty())
        {
            ans += to_string(s.top());
            s.pop();
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
// } Driver Code Ends