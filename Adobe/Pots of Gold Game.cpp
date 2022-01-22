// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findMaxCoins(vector<int> coin, int i, int j, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
        {
            dp[i][j] = coin[i];
            return coin[i];
        }
        if (i + 1 == j)
        {
            dp[i][j] = max(coin[i], coin[j]);
            return max(coin[i], coin[j]);
        }
        int start = coin[i] + min(findMaxCoins(coin, i + 2, j, dp), findMaxCoins(coin, i + 1, j - 1, dp));
        int end = coin[j] + min(findMaxCoins(coin, i + 1, j - 1, dp), findMaxCoins(coin, i, j - 2, dp));
        dp[i][j] = max(start, end);
        return max(start, end);
    }
    int maxCoins(vector<int> &arr, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return findMaxCoins(arr, 0, n - 1, dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends