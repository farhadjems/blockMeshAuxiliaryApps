#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double a0, an;
    std::cout << "Insert a0: ";
    std::cin >> a0;

    std::cout << "Insert an: ";
    std::cin >> an;

    std::cin.ignore();

    double delta = an / a0;

    double q{};

    std::cout << std::setw(20) << "q" << std::setw(20) << "n" << std::endl;
    ;
    for (double n = 2;; n++)
    {
        q = pow(delta, 1.0 / n);

        std::cout << std::setw(20) << std::setprecision(15) << q << std::setw(20) << std::setprecision(15) << n << std::endl;
        std::cin.get();
    }
}