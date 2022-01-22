// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void add_edge(vector<int> adj[], int i, int j)
    {
        adj[i].push_back(j);
    }
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        vector<int> adj[N];
        int indegree[N];
        bool vis[N];
        bool check[N];
        for (int i = 0; i < N; i++)
        {
            check[i] = true;
            vis[i] = false;
            indegree[i] = 0;
        }
        for (int i = 0; i < prerequisites.size(); i++)
        {
            check[prerequisites[i].first] = true;
            check[prerequisites[i].second] = true;
            if (prerequisites[i].first == prerequisites[i].second)
                return false;
            add_edge(adj, prerequisites[i].second, prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0 and check[i])
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
            count++;
        }
        return count == N;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends