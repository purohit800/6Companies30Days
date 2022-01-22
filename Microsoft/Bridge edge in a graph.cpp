// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> adj[], bool vis[], int s)
    {
        vis[s] = true;
        for (auto i : adj[s])
            if (!vis[i])
                dfs(adj, vis, i);
    }
    int dfs_rec(vector<int> adj[], int V)
    {
        bool vis[V];
        int ans = 0;
        for (int i = 0; i < V; i++)
            vis[i] = false;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(adj, vis, i);
                ans++;
            }
        }
        return ans;
    }
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        int t = dfs_rec(adj, V);
        vector<int> adj1[V];
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                if (i == c && j == d)
                    continue;
                if (i == d && j == c)
                    continue;
                adj1[i].push_back(j);
            }
        }
        int x = dfs_rec(adj1, V);
        if (t != x)
            return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends