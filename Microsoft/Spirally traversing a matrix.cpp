// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        int row_start = 0, row_end = r - 1, col_start = 0, col_end = c - 1;
        vector<int> v;
        while (row_start <= row_end)
        {
            for (int j = col_start; j <= col_end; j++)
                v.push_back(matrix[row_start][j]);
            row_start++;
            if (v.size() == r * c)
                break;
            for (int j = row_start; j <= row_end; j++)
                v.push_back(matrix[j][col_end]);
            col_end--;
            if (v.size() == r * c)
                break;
            for (int j = col_end; j >= col_start; j--)
                v.push_back(matrix[row_end][j]);
            row_end--;
            if (v.size() == r * c)
                break;
            for (int j = row_end; j >= row_start; j--)
                v.push_back(matrix[j][col_start]);
            col_start++;
            if (v.size() == r * c)
                break;
        }

        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends