class Solution
{
public:
    bool isValid(vector<int> v1)
    {
        int start = v1.size() - 1;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] < start)
                return false;
            start--;
        }
        return true;
    }
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                    break;
                count++;
            }
            v.push_back(count);
        }
        bool a = false;
        int count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < v.size(); i++)
            mp[v[i]] = i;
        vector<int> v1 = v;
        sort(v1.begin(), v1.end(), greater<int>());
        int start = n - 1;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] < start)
                return -1;
            start--;
        }
        while (!isValid(v))
        {
            for (int i = 0; i < v1.size(); i++)
            {
                if (v[i] < n - 1 - i)
                {
                }
                start--;
            }
        }
        return count;
    }
};