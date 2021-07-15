#include <iostream>
#include <unistd.h>
#include <cmath>

using namespace std;

class donut
{
public:
    int angle1;
    int angle2;
    int angle3;
    float d1;
    float d2;
    float d3;
    float r1;
    float r2;
    float rota_axis[2] = {45 / 180 * M_PI_2, 0 / 180 * M_PI_2};
    float rota_speed = 10;
    float ll_ro_speed = 0.1;
    char lit[13] = ".,-~:;=!#%$@";
    int degree;

    donut(int i, int a, int j, int b, int c, float d)
    {
        angle1 = i;
        angle2 = a;
        angle3 = j;
        r1 = b;
        r2 = c;
        degree = d;
    }
    void start()
    {
        while (1)
        {
            d1 = M_PI * angle1 / 180;
            d2 = M_PI * angle2 / 180;
            d3 = M_PI * angle3 / 180;
            float li_sor = M_PI * degree / 180;
            for (int j = 0; j < BREADTH; j++)
            {
                for (int i = 0; i < LONG; i++)
                {
                    float p = r1 + r2 + 1;
                    float cosa = cos(d1);
                    float sina = sin(d1);
                    float cosb = cos(d2);
                    float sinb = sin(d2);
                    float sinc = sin(d3);
                    float cosc = cos(d3);
                    float x = i - LONG / 2;
                    float z = (j - BREADTH / 2) * 2;
                    bool draw = false;
                    float sint;
                    float cost;
                    for (float t = 0; t < p * 2; t += 1)
                    {
                        float _x = x * cosa * cosc + (t - p) * sina + sinc * z;
                        float _y = -x * sina + (t - p) * cosa * cosb * cosc + z * sinb;
                        float _z = -x * sinc - (t - p) * sinb + z * cosb;
                        float d = sqrt(_x * _x + _z * _z);
                        sint = (d - r1) / r2;
                        if ((int)sint >= -1 && (int)sint <= 1)
                        {
                            float h1 = _y;
                            cost = sqrt(1 - sint * sint);
                            float h2 = r2 * cost;
                            draw = h1 < 0 ? -h1 <= h2 : h1 <= h2;
                            sint *= _z / d;
                            if (draw)
                                break;
                        }
                    }
                    if (draw)
                    {
                        int k = (-sint + 1) * 6;
                        cout.put(lit[k]);
                    }
                    else
                        cout.put(' ');
                }
                cout.put('\n');
            }
            usleep(100);
            cout << "\x1D[2J";
            cout << "\x1B[H";
            angle1 = (angle1 + 1) % 360;
            angle2 = (angle2 + 0) % 360;
            angle3 = (angle3 + 0) % 360;
        }
    }

private:
    int LONG = 80;
    int BREADTH = 40;
};

int main()
{
    donut two(0, 0, 0, 20.0, 9.0, 0);
    two.start();
}