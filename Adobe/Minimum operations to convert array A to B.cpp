// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int lis(vector<int> v)
    {
        if (v.size() == 0)
            return 0;
        vector<int> ans;
        ans.push_back(v[0]);
        for (int i = 1; i < v.size(); i++)
        {
            if (ans.back() < v[i])
                ans.push_back(v[i]);
            else
            {
                int j = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
                ans[j] = v[i];
            }
        }
        return ans.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < M; i++)
        {
            mp[B[i]]++;
        }
        for (int i = 0; i < N; i++)
        {
            if (mp[A[i]] > 0)
                res.push_back(A[i]);
        }
        int len = lis(res);
        return N + M - (2 * len);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
} // } Driver Code Ends