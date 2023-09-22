#include <stack>
#include <iostream>

using namespace std;

#define endl "\n"

int num, currCoach;
stack<int> coaches;

void check()
{
    while (true) 
    {
        while (coaches.size() > 0)
            coaches.pop();
        int j = 0;
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &currCoach);
            if (currCoach == 0)
                return;

            while (j < num && j != currCoach)
            {
                if (coaches.size() > 0 && coaches.top() == currCoach)
                    break;
                j++;
                coaches.push(j);
            }
            if (coaches.top() == currCoach)
                coaches.pop();
        }
        if (coaches.size() == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main()
{
    while (true)
    {
        scanf("%d", &num);
        if (num == 0)
            break;

        check();
        cout << endl;
    }
}