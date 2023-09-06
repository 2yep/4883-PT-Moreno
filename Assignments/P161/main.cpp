#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define endl '\n'
#define pb push_back
#define maxHours 18000

using namespace std;

int main()
{
    int cTime, elapTime = 0;
    vector<int> times;
    bool Green = false;

    // Cycle time must exist and != 0
    while (cin >> cTime && cTime)
    {
        times.pb(cTime);
        // Stop reading in cycle times when 0 is entered
        while (cTime)
        {
            times.pb(cTime);
            cin >> cTime;
        }

        // Start at the lowest cycle time, then double it to find the next time
        // all lights will be green
        elapTime = *min_element(times.begin(), times.end()) * 2;

        do
        {
            Green = true;
            for (int tempTime : times)
            {
                if (!(elapTime % (tempTime * 2) < (tempTime - 5)))
                {
                    Green = false;
                    break;
                }
            }
            // Test if lights are all green until 5 hours have passed
        } while (!(Green) && ++elapTime <= maxHours);

        // If all lights are green, print the time
        if (Green)
        {
            int hour = elapTime / 3600;
            int min = (elapTime % 3600) / 60;
            int sec = (elapTime % 3600) % 60;
            cout << setfill('0') << setw(2) << hour << ':'
                 << setw(2) << min << ':' << setw(2) << sec << endl;
        }
        else
        {
            cout << "Signals fail to synchronise in 5 hours" << endl;
        }

        // reset variables for next scenario
        times.clear();
        Green = false;
    }

    return 0;
}