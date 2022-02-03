class Solution
{
public:
    int height(int N)
    {
        N = 8 * N;
        return (-1 + sqrt(N + 1)) / 2;
    }
};