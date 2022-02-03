class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        unordered_map<int, int> mp;
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int x = abs(points[i][0] - points[j][0]);
                x = x * x;
                int y = abs(points[i][1] - points[j][1]);
                y = y * y;
                int d = x + y;
                mp[d]++;
            }
            for (auto i : mp)
                ans += i.second * (i.second - 1);
            mp.clear();
        }
        return ans;
    }
};