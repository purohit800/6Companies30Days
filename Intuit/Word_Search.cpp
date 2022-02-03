// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool isValid(int i, int j, int n, int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    bool rec(int i, int j, vector<vector<char>> board, vector<vector<bool>> &vis, int x, string word, int res)
    {
        if (word.size() == res)
            return true;
        int n = board.size();
        int m = board[0].size();
        for (int k = 0; k < 4; k++)
        {
            if (isValid(i + dx[k], j + dy[k], n, m) and x < word.size() and board[i + dx[k]][j + dy[k]] == word[x] and !vis[i + dx[k]][j + dy[k]])
            {
                vis[i + dx[k]][j + dy[k]] = true;
                if (rec(i + dx[k], j + dy[k], board, vis, x + 1, word, res + 1))
                    return true;
                vis[i + dx[k]][j + dy[k]] = false;
            }
        }
        return false;
    }
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] and !vis[i][j])
                {
                    vis[i][j] = true;
                    int s = 1;
                    if (rec(i, j, board, vis, start + 1, word, s))
                        return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
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
        vector<vector<char>> board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends