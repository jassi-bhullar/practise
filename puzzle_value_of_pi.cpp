// you are given rand() which gives number
// from 0.0 to 1.0, calculate pi

#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    float x, y;

    float GetDistSqr()
    {
        return x*x + y*y;
    }
};

float getRandFloat()
{
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}
//adding some comment for learning git , feature2 
int main()
{
    int cnt_inside = 0;

	Point p;

    int N = 10000000;
    float t = N;

    while(t--)
    {
        p.x = getRandFloat();
        p.y = getRandFloat();
        float d = p.GetDistSqr();

        if(d < 1.0)
        {
            cnt_inside++;
        }
    }

    float pi = cnt_inside * 4.0 / static_cast<float>(N);

    cout << pi << endl;

	return 0;
}