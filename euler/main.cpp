#include <iostream>

using namespace std;

// Euler method for radiation decay
// for k = 1
// implemented equation: r(n+1) = r(n) - k*r(n)*delta
// r(0) = 1;
void eulerRadiation(double delta, double k)
{
    constexpr double timeLimit = 3.0;
    double time = 0.0;
    double r = 1.0;

    while(time < timeLimit)
    {
        cout << "\ttime: " << time << "\twartosc: " << r << endl;
        r = r - k * r * delta;
        time = time + delta;
    }
}

// step method for problem as above
double firstStepForStepMethod(double initValue, double delta, double k, uint16_t factor);
void stepMethodRadiation(double initValue, double delta, double k)
{
    cout << "\n\tSTEP METHOD\n";
    constexpr double timeLimit = 3.0;
    double time = 2.0 * delta;
    double nn1Value = initValue;
    double n1Value, n2Value = nn1Value;
    double r = firstStepForStepMethod(initValue, delta, k, 100);

    cout << "\tfirst value: " << r << endl;

    while(time < timeLimit)
    {

        n1Value = nn1Value - (k * r) * 2.0 * delta;
        n2Value = r - (k * n1Value) * 2.0 * delta;

        nn1Value = r;
        r = n1Value;
        n1Value = n2Value;

        cout << "\ttime: " << time << "\twartosc: " << n2Value << endl;

        time = time + delta;
    }
}

double firstStepForStepMethod(double initValue, double delta, double k, uint16_t factor)
{
    if(factor == 1)
        return initValue;

    double r = initValue;

    for(uint16_t i = 0; i < factor; ++i)
        r = r - k * r * delta / static_cast<double>(factor);

    return r;
}

int main()
{
    double delta = 0.1;
    double k_factor = 1.0;

    eulerRadiation(delta, k_factor);

   // delta = 0.5;
    stepMethodRadiation(1.0, delta, k_factor);

    return 0;
}
