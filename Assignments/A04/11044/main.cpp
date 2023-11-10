#include <iostream>

using namespace std;

int main()
{
    int t, width, height;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &width, &height);
        printf("%d\n", (width / 3) * (height / 3));
    }

    return 0;
}