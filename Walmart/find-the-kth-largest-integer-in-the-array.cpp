class Solution
{
public:
    bool cmp(string s1, string s2)
    {
        if (s1.size() == s2.size())
            return s1 > s2;
        else
            return s1.size() > s2.size();
    }
    struct mycmp
    {
        bool operator()(string s1, string s2)
        {
            if (s1.size() == s2.size())
                return s1 > s2;
            else
                return s1.size() > s2.size();
        }
    };
    string kthLargestNumber(vector<string> &nums, int k)
    {
        priority_queue<string, vector<string>, mycmp> pq;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            if (cmp(nums[i], pq.top()))
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};