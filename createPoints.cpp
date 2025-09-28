#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> X = {"$xo0 ", "$xc1 ", "$x1 ", "$x2 ", "$x3 ", "$x4 ", "$xc2 ", "$xo5 "};
    vector<string> Y = {"$y0 ", "$y1 ", "$yc ", "$y3 "};
    vector<string> Z = {"$z4", "$zc1 ", " $zc2 ", " $z5 "};

    ofstream oFile("points.txt");
    if (!oFile.is_open())
    {
        cerr << "could not create the output file, exiting...\n";
    }

    for (auto &z : Z)
    {
        for (auto &y : Y)
        {
            for (auto &x : X)
            {
                oFile << "(" << x << y << z << ")" << endl;
            }
        }
    }
}