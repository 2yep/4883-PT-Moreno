#include <cstdio>

using namespace std;

int main()
{
    int testCases;
    int a;
    int b;
    int oddSum;

    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        oddSum = 0;
        scanf("%d%d", &a, &b);
        for (int i = a; i <= b; i++)

            if (i % 2)
                oddSum += i;

        printf("Case %d: %d\n", t, oddSum);
    }
    return 0;
}