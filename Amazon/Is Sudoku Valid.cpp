// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        bool box[9];
        int pos[3] = {0, 3, 6};
        bool row[9][9], col[9][9];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                row[i][j] = false;
                col[i][j] = false;
            }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if (mat[i][j] == 0)
                    continue;
                if (row[i][mat[i][j] - 1] || col[j][mat[i][j] - 1])
                    return false;
                row[i][mat[i][j] - 1] = true;
                col[j][mat[i][j] - 1] = true;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int rs = pos[i];
                int es = pos[j];
                for (int k = 0; k < 9; k++)
                    box[k] = false;
                for (int x = rs; x < rs + 3; x++)
                    for (int y = es; y < es + 3; y++)
                    {
                        if (mat[x][y] == 0)
                            continue;
                        else if (box[mat[x][y] - 1])
                            return false;
                        box[mat[x][y] - 1] = true;
                    }
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
} // } Driver Code Ends