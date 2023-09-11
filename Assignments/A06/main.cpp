#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cstdio>

#define endl "\n"

using namespace std;

int main()
{
    int n;
    string treeName;
    map<string, int> treeRecord;

    scanf("%d", &n);

    // set precision to 4 decimal places
    cout << fixed << setprecision(4);

    // empty line fix, this input is weird
    getchar();
    getchar();

    while (n--) // while n is not 0
    {
        double treeCount = 0; // total count of all trees

        // map to store tree name and its count
        map<string, int> treeRecord;

        while (true)
        {
            getline(cin, treeName); 
            if (treeName == "")     
                break;

            treeRecord[treeName]++; 
            treeCount++;           
        }

        // iterate through map
        for (auto i = treeRecord.begin(); i != treeRecord.end(); i++)
        {
            // print tree name and its percentage
            cout << i->first << " " << i->second / treeCount * 100.0 << endl;
        }

        if (n != 0) 
        cout << endl; 
    }
}