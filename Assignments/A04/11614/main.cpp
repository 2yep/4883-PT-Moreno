#include <cmath>
#include <cstdio>

using namespace std;

#define ll long long

int main()
{
    int testCases;
    ll num, squareRoot, ans;

    scanf("%d", &testCases);
    for (int i = 1; i <= testCases; i++)
    {
        scanf("%lld", &num);
        squareRoot = sqrt((num * 8) + 1);
        ans = (squareRoot - 1) / 2;
        printf("%lld\n", ans);
    }
}