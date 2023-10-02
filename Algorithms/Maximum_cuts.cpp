#include <bits/stdc++.h>
using namespace std;

int dp[10005];

int func(int l, int p, int q, int r)
{
    if (l == 0)
        return 0;

    if (dp[l] != -1)
        return dp[l];

    int a(INT_MIN), b(INT_MIN), c(INT_MIN);

    if (p <= l)
        a = func(l - p, p, q, r);

    if (q <= l)
        b = func(l - q, p, q, r);

    if (r <= l)
        c = func(l - r, p, q, r);

    return dp[l] = 1 + max({ a, b, c });
}

int maximizeTheCuts(int l, int p, int q, int r)
{
    memset(dp, -1, sizeof(dp));
    int ans = func(l, p, q, r);

    if (ans < 0)
        return 0;
    return ans;
}

int main()
{
    int l, p, q, r;
    cout << "ENTER THE LENGTH OF THE ROD " << endl;
    cin >> l;

    cout << "ENTER THE VALUES OF p, q & r " << endl;
    cin >> p >> q >> r;

    cout << "THE MAXIMUM NUMBER OF SEGMENTS THAT CAN BE CUT OF LENGTH p, q & r FROM A ROD OF LENGTH l are " << maximizeTheCuts(l, p, q, r) << endl;
    return 0;
}