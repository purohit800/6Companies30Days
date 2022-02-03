class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int a = 0, b = 0;
        if (colors.size() < 3)
            return false;
        for (int i = 0; i < colors.size() - 2; i++)
        {
            if (colors[i] == 'A' and colors[i + 1] == 'A' and colors[i + 2] == 'A')
                a++;
            if (colors[i] == 'B' and colors[i + 1] == 'B' and colors[i + 2] == 'B')
                b++;
        }
        return a > b;
    }
};