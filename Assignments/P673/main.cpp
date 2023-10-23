#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    int n;
    int f = 0;
    int stacksize = 0;
    int c = 0;

    cin >> n;

    while (c <= n)
    {
        stack<char> pStack;

        c++;

        f = 0;

        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                pStack.push(s[i]);
            }
            else if (s[i] != ' ')
            {
                if (pStack.size())
                {
                    char c = pStack.top();
                    if (s[i] == ')' && c != '(')
                    {
                        f = 1;
                        break;
                    }
                    else if (s[i] == ']' && c != '[')
                    {
                        f = 1;
                        break;
                    }
                    else
                    {
                        pStack.pop();
                    }
                }
                else
                {
                    f = 1;
                    break;
                }
            }
            stacksize = pStack.size();
        }
        if (c > 1)
        {
            if ((f == 0 && stacksize == 0) || s.length() == 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
