#include <iostream>

using namespace std;

// metoda Eulera dla rozkładu promieniotwórczego
// dla k = 1
// zaimplementowany wzór to r(n+1) = r(n) - k*r(n)*delta
// r(0) = 1;
void eulerRadiation(double delta, double k)
{
    constexpr double timeLimit = 2.0;
    double time = 0.0;
    double r = 1.0;

    while(time < timeLimit)
    {
        cout << "\ttime: " << time << "\twartosc: " << r << endl;
        r = r - k * r * delta;
        time = time + delta;
    }
}

int main()
{
    eulerRadiation(0.1, 0.01);
    return 0;
}
