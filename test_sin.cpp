#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <unistd.h>

using namespace std;

int main()
{
    char l[13] = ".,-~:;=!#%$@";
    int g = 1;
    int d1 = 0;
    int d2 = 0;
    while (1)
    {
        int r1 = 15;
        int r2 = 10;
        cout << "\x1B[H";
        cout << "\x1D[2J";
        d1 += 2;
        d1 = d1 % 360;
        d2 += 1;
        d2 = d2 % 360;
        float phi = M_PI * d1 / 180;
        float alpha = M_PI * d2 / 180;
        for (int j = 0; j < 40; j++)
        {
            for (int i = 0; i < 80; i++)
            {
                float sina = sin(alpha);
                float cosa = cos(alpha);
                float sinb = sin(phi);
                float cosb = cos(phi);
                float _z = (j - 20) * 2;
                float _x = i - 40;
                float x = _x / cosa;
                float z = _z / cosb;
                float sinp = x / sqrt(x * x + z * z);
                float cosp = z / sqrt(x * x + z * z);
                float cost = (x - sinp * r1) / (sinp * r2);
                float sint = sqrt(1 - cost * cost);
                if (cost > -1 && cost < 1)
                {
                    float c = (cost * cosa - sint * sina);
                    int k = ((c * (-cosp) + 1) * 6);
                    cout << l[k];
                }
                else
                    cout << " ";
            }
            cout << endl;
        }
        usleep(1000);
    }
}
//