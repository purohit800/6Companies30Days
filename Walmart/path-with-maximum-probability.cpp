class Solution
{
public:
    void add_edge(vector<int> adj[], int i, int j)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    bool check(vector<int> adj[], int start, int end, bool vis[])
    {
        vis[start] = true;
        if (start == end)
            return true;
        for (auto i : adj[start])
            if (!vis[i])
                if (check(adj, i, end, vis))
                    return true;
        return false;
    }
    void dfs(vector<int> adj[], int start, int end, bool vis[], double val)
    {
        vis[start] = true;
        if (start == end)
            return;
    }
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        map<vector<int>, double> mp;
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            add_edge(adj, edges[i][0], edges[i][1]);
            mp[{edges[i][0], edges[i][1]}] = succProb[i];
            mp[{edges[i][1], edges[i][0]}] = succProb[i];
        }
        bool vis[n];
        for (int i = 0; i < n; i++)
            vis[i] = false;
        if (!check(adj, start, end, vis))
            return 0;
        for (int i = 0; i < n; i++)
            vis[i] = false;
    }
};