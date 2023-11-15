#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define newl '\n'

int main()
{
    int numCases;
    int numMatches;
    int output;
    string num;

    vector<pair<string, int>> nums = {{"one", 1}, {"two", 2}, {"three", 3}};

    cin >> numCases;

    while (numCases--)
    {
        numMatches = 0;
        cin >> num;
        for (auto &&p : nums)
        {
            if (num.size() == p.first.size())
            {
                for (int i = 0; i < num.size(); i++)
                    if (num[i] == p.first[i])
                        numMatches++;

                if (numMatches == p.first.size() || numMatches == p.first.size() - 1)
                {
                    output = p.second;
                    break;
                }
            }
        }
        cout << output << newl;
    }
}