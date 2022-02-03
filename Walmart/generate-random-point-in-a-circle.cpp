class Solution
{
public:
    double r, x, y;
    Solution(double radius, double x_center, double y_center)
    {
        r = radius;
        x = x_center;
        y = y_center;
    }
    vector<double> randPoint()
    {
        double rand1 = (double)rand() / RAND_MAX;
        double theta = 2 * 3.14159 * rand1;
        double rand2 = (double)rand() / RAND_MAX;
        double length = (double)sqrt(rand2) * r;
        double x1 = x + length * cos(theta);
        double y1 = y + length * sin(theta);
        return {x1, y1};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */