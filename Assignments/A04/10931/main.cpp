#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define newl '\n'

int main()
{
    bitset<32> bin;
    int val;

    while (cin >> val && val)
    {
        bin = val;
        string str_bin = bin.to_string();
        int i = str_bin.find("1");
        str_bin = str_bin.substr(i);
        cout << "The parity of " << str_bin << " is " << bin.count() << " (mod 2).\n";
    }
}