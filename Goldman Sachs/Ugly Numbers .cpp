// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        unordered_map<ull, ull> mp;
        priority_queue<ull, vector<ull>, greater<ull>> pq;
        mp[1]++;
        pq.push(1);
        ull ans;
        for (ull i = 0; i < n; i++)
        {
            ull a = pq.top();
            ans = a;
            pq.pop();
            ull b = a * 2;
            ull c = a * 3;
            ull d = a * 5;
            if (mp[b] == 0)
            {
                mp[b]++;
                pq.push(b);
            }
            if (mp[c] == 0)
            {
                mp[c]++;
                pq.push(c);
            }
            if (mp[d] == 0)
            {
                mp[d]++;
                pq.push(d);
            }
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
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends