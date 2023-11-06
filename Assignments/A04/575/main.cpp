#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define newl '\n'

int main()
{
    string sBin; // skew binary number
    int bin;     // normal binary number

    while (cin >> sBin && sBin != "0")
    {
        bin = 0;
        for (int i = 0; i < sBin.size(); i++)
        {
            bin += ((int)sBin[i] - 48) * (pow(2, sBin.size() - i) - 1);
        }

        cout << bin << newl;
    }
}