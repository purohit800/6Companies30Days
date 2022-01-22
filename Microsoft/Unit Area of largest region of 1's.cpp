// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find unit area of the largest region of 1s.
    vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dy = {-1, 1, 0, 1, -1, 0, 1, -1};
    bool isValid(int i, int j, int n, int m)
    {
        return i < n && j < m && i >= 0 && j >= 0;
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        bool vis[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                vis[i][j] = false;
        }
        int res = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    vis[i][j] = true;
                    q.push(make_pair(i, j));
                }
                int mx = 0;
                while (!q.empty())
                {
                    mx++;
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();
                    for (int k = 0; k < 8; k++)
                    {
                        if (isValid(a + dx[k], b + dy[k], n, m) && grid[a + dx[k]][b + dy[k]] == 1 && !vis[a + dx[k]][b + dy[k]])
                        {
                            vis[a + dx[k]][b + dy[k]] = true;
                            q.push(make_pair(a + dx[k], b + dy[k]));
                        }
                    }
                }
                res = max(res, mx);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends