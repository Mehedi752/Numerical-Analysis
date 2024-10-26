// Mehedi Hasan @Mehedi752
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define MOD 1000000007

double errorFind(double previousC, double actualC)
{
    return abs(actualC - previousC) / actualC;
}

double f(double x)
{
    return 3 * x - cos(x) - 1;
}

double falsePositionMethod(double a, double b, double approximateError)
{
    double temporaryError = 1, c = b, previousC;

    // When temporary error will reached less or equal than approxiamte error our loop will be broken.
    while (temporaryError > approximateError)
    {
        previousC = c, c = (a * f(b) - b * f(a)) / (f(b) - f(a));;

        if (f(c) == 0)
            break;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        // cout << c << " " << previousC << '\n';
        temporaryError = errorFind(previousC, c);
    }
    return c;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    double a, b, approximateError = 0.0000000000001;
    cin >> a >> b;
    double root = falsePositionMethod(a, b, approximateError);
    cout << "Root of a Equation by using False Position Method : " << root << '\n';
}