class Solution
{
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool isValid(int i, int j, int n, int m)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    }
    bool touch_atlantic(int i, int j, int n, int m)
    {
        return i == n - 1 or j == m - 1;
    }
    bool touch_pacific(int i, int j)
    {
        return i == 0 or j == 0;
    }
    bool check_atlantic(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> heights, vector<vector<bool>> &checker)
    {
        vis[i][j] = true;
        int n = heights.size();
        int m = heights[0].size();
        if (touch_atlantic(i, j, n, m))
        {
            checker[i][j] = true;
            return true;
        }
        for (int k = 0; k < 4; k++)
        {
            if (isValid(i + dx[k], j + dy[k], n, m) and heights[i][j] >= heights[i + dx[k]][j + dy[k]] and !vis[i + dx[k]][j + dy[k]])
            {
                vis[i + dx[k]][j + dy[k]] = true;
                checker[i][j] = checker[i][j] or check_atlantic(i + dx[k], j + dy[k], vis, heights, checker);
            }
        }
        return checker[i][j];
    }
    bool check_pacific(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> heights, vector<vector<bool>> &checker)
    {
        vis[i][j] = true;
        int n = heights.size();
        int m = heights[0].size();
        if (touch_pacific(i, j))
        {
            checker[i][j] = true;
            return true;
        }
        for (int k = 0; k < 4; k++)
        {
            if (isValid(i + dx[k], j + dy[k], n, m) and heights[i][j] >= heights[i + dx[k]][j + dy[k]] and !vis[i + dx[k]][j + dy[k]])
            {
                vis[i + dx[k]][j + dy[k]] = true;
                checker[i][j] = checker[i][j] or check_pacific(i + dx[k], j + dy[k], vis, heights, checker);
            }
        }
        return checker[i][j];
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));
        vector<vector<bool>> check1(n, vector<bool>(m, false));
        vector<vector<bool>> check2(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis2[i][j])
                {
                    vis2[i][j] = true;
                    bool a = check_pacific(i, j, vis2, heights, check2);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis1[i][j])
                {
                    vis1[i][j] = true;
                    bool a = check_atlantic(i, j, vis1, heights, check1);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << check1[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << check2[i][j] << " ";
            }
            cout << endl;
        }
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check1[i][j] and check2[i][j])
                    v.push_back({i, j});
            }
        }
        return v;
    }
};