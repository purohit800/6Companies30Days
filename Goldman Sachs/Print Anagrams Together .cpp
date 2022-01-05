class Solution
{
public:
    vector<string> remove_dup(vector<string> s)
    {
        unordered_map<string, int> m;
        vector<string> v;
        for (auto i : s)
        {
            if (m[i] == 0)
            {
                m[i]++;
                v.push_back(i);
            }
        }
        return v;
    }
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        vector<string> v;
        for (string i : string_list)
        {
            string a = i;
            sort(a.begin(), a.end());
            mp[a].push_back(i);
            v.push_back(a);
        }
        v = remove_dup(v);
        for (auto i : v)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};