class Solution
{
public:
    int findPosition(int N, int M, int K)
    {
        K--;
        M--;
        return (M + K) % N + 1;
    }
};