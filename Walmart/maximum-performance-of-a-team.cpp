typedef pair<int, int> pi;
class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        int mod = 1000000007;
        priority_queue<pi> pq;
        for (int i = 0; i < n; i++)
            pq.push(make_pair(efficiency[i], speed[i]));
        priority_queue<pi, vector<pi>, greater<pi>> pq1;
        long long int total_speed = 0, eff = 0;
        long long int ans = 0;
        int i = 0;
        while (!pq.empty())
        {
            if (pq1.size() == k)
            {
                int s = pq1.top().first;
                int e = pq1.top().second;
                pq1.pop();
                total_speed -= s;
            }
            int e1 = pq.top().first;
            int s1 = pq.top().second;
            pq.pop();
            pq1.push(make_pair(s1, e1));
            total_speed += s1;
            eff = e1;
            long long int a = (total_speed * eff);
            if (a > ans)
                ans = a;
            i++;
        }
        return ans % mod;
    }
};