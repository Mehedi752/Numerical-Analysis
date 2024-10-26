// Mehedi Hasan @Mehedi752
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define MOD 1000000007

double errorFind(double c_experimental, double c_actual)
{
    return abs(c_experimental - c_actual) / c_actual;
}

double f(double x)
{
    return 3 * x - cos(x) - 1;
}

double bisectionMethod(double a, double b, double ea)
{
    double error_tm = 1, c = b, c_experimental;
    while (error_tm > ea)
    {
        c_experimental = c;
        c = (a + b) / 2;

        if (f(c) == 0)
            break;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        error_tm = errorFind(c_experimental, c);
    }
    return c;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    double a, b, ea = 0.0000000000001;
    cin >> a >> b;
    double root = bisectionMethod(a, b, ea);
    cout << root << endl;
}
