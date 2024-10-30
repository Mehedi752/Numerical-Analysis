// Mehedi Hasan @Mehedi752
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define MOD 1000000007

// Function for Error Finding.
double errorFind(double a, double b)
{
    return abs(b - a);
}

double errorFindingByTemporarayError(double presentC, double previousC)
{
    return abs((presentC - previousC) / presentC);
}

// Function for the Equation.
double f(double x)
{
    return 3 * x - cos(x) - 1; //(x * x * x) - (x * x) + 2
}

int totalSteps = 0;
double falsePositionMethod(double a, double b, double approximateError)
{
    double c = b, temporaryError = 1, previousC, countA = 0, countB = 0;

    // When temporary error will reached less or equal than approxiamte error our loop will be broken.
    while (abs(temporaryError) >= approximateError)
    {
        previousC = c;
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) == 0)
            break;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        totalSteps++;

        // cout << a << " " << b << " " << c << '\n';
        temporaryError = errorFind(a, b);
        // temporaryError = errorFindingByTemporarayError(c,previousC);
        // cout << temporaryError << '\n';
    }
    return c;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    double a, b, approximateError = 0.0000001;
    cin >> a >> b;
    if (f(a) * f(b) >= 0)
    {
        cout << "Incorrect interval. The function must have different signs at a and b." << '\n';
        return 0;
    }
    double root = falsePositionMethod(a, b, approximateError);
    cout << "Root of the Equation by using False Position Method : " << root << '\n'
         << " " << '\n';
    cout << "Total Steps Needed for Finding the Root : " << totalSteps << '\n';
}
