class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, bool vis[], int i)
    {
        vis[i] = true;
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j] == 1 && !vis[j])
            {
                vis[j] = true;
                dfs(isConnected, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0;
        bool vis[isConnected.size()];
        for (int i = 0; i < isConnected.size(); i++)
            vis[i] = false;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(isConnected, vis, i);
            }
        }
        return ans;
    }
};