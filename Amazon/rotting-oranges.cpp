class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool isValid(int i, int j, int n, int m)
    {
        return i < n && j < m;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        bool vis[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
                if (grid[i][j] == 2)
                {
                    vis[i][j] = true;
                    vector<int> v = {i, j, 0};
                    q.push(v);
                }
            }
        }
        int cost = 0;
        while (!q.empty())
        {
            int i = q.front()[0];
            int j = q.front()[1];
            int c = q.front()[2];
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                if (isValid(i + dx[k], j + dy[k], n, m) && grid[i + dx[k]][j + dy[k]] == 1 && !vis[i + dx[k]][j + dy[k]])
                {
                    vis[i + dx[k]][j + dy[k]] = true;
                    vector<int> v = {i + dx[k], j + dy[k], c + 1};
                    cost = max(cost, c + 1);
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    cost = -1;
            }
        }
        return cost;
    }
};