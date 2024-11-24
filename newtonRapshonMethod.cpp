// Mehedi Hasan @Mehedi752
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define MOD 1000000007
double approximateError = 0.0001;

// Function for Error Finding.
double errorFind(double newX, double oldX)
{
    return abs(newX - oldX);
}

double errorFindingByTemporarayError(double presentX, double previousX)
{
    return abs((presentX - previousX) / presentX);
}

// Function for the Equation.
double f(double x)
{
    return (x * x * x * x * x * x * x * x * x * x) - 1;
}

double derivativeOfFunction(double x)
{
    return 10 * (x * x * x * x * x * x * x * x * x);
}

double doubleDerivativeOffunction(double x)
{
    return 90 * (x * x * x * x * x * x * x * x);
}

int totalSteps = 0;
void newtonRaphsonMethod(double x)
{
    double temporaryError = 1, previousX;

    // When temporary error will reached less or equal than approxiamte error our loop will be broken.
    while (abs(temporaryError) >= approximateError)
    {
        previousX = x;
        double df = derivativeOfFunction(x), dff = doubleDerivativeOffunction(x);
        if (df == 0)
        {
            cout << "Derivative of the Function is Zero. So, Newton Raphson Method is not Applicable." << '\n';
            return;
        }
        x = x - (f(x)*df / ((df * df) - (f(x) * dff)));
        totalSteps++;

        temporaryError = errorFind(x, previousX);
        // temporaryError = errorFindingByTemporarayError(x, previousX);
        cout << temporaryError << '\n';
    }

    double root = x;
    cout << "Root of the Equation by using Newton Raphson Method : " << root << '\n'
         << " " << '\n';
    cout << "Total Steps Needed for Finding the Root : " << totalSteps << '\n';
}

void modifiedNewtonRaphsonMethod(double x)
{
    double temporaryError = 1, previousX;

    // When temporary error will reached less or equal than approxiamte error our loop will be broken.
    while (abs(temporaryError) >= approximateError)
    {
        previousX = x;
        double df = derivativeOfFunction(x);
        if (df == 0)
        {
            cout << "Derivative of the Function is Zero. So, Newton Raphson Method is not Applicable." << '\n';
            return;
        }
        x = x - (f(x) / df);
        totalSteps++;

        temporaryError = errorFind(x, previousX);
        // temporaryError = errorFindingByTemporarayError(x, previousX);
        cout << temporaryError << '\n';
    }

    double root = x;
    cout << "Root of the Equation by using Modified Newton Raphson Method : " << root << '\n'
         << " " << '\n';
    cout << "Total Steps Needed for Finding the Root : " << totalSteps << '\n';
}

void secantMethod(double x0, double x1)
{
    double temporaryError = 1, x2;

    // When temporary error will reached less or equal than approxiamte error our loop will be broken.
    while (abs(temporaryError) >= approximateError)
    {
        double slope = (x1 - x0) / (f(x1) - f(x0));
        x2 = x1 - (f(x1) * slope);
        totalSteps++;

        x0 = x1, x1 = x2;
        temporaryError = errorFind(x1, x0);
        // temporaryError = errorFindingByTemporarayError(x2, previousX);
        cout << temporaryError << '\n';
    }

    double root = x2;
    cout << "Root of the Equation by using Secant Method : " << root << '\n'
         << " " << '\n';
    cout << "Total Steps Needed for Finding the Root : " << totalSteps << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // Input For Newton Raphson Method.
    double initialGuess;
    cin >> initialGuess;

    // Input For Secant Method.
    double initialGuess1, initialGuess2;
    cin >> initialGuess1 >> initialGuess2;

    // newtonRaphsonMethod(initialGuess);
    modifiedNewtonRaphsonMethod(initialGuess);
    secantMethod(initialGuess1, initialGuess2);
}