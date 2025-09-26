#include <iostream>
#include <cmath>
#include <iomanip>

double q1, q2, a0, L;
int n = 0;

double func(double q)
{
    double result = a0 * (1 - pow(q, n)) / (1 - q) - L;
    return result;
}

double avg(double num1, double num2)
{
    double result = (num1 + num2) / 2;
    return result;
}

double Abs(double num)
{
    if (num < 0)
    {
        return (-num);
    }

    return num;
}

double biSection()
{
    if (func(q1) * func(q2) > 0)
    {
        std::cerr << " inserted initial guess for q1 and q2 are not suitable!\n";
        std::cout << func(q1) << '\t' << func(q2) << std::endl
                  << "quitting...\n";
        throw "error in initialization";
    }

    double q = 0;
    double fQ = 0;
    double fQ1 = 0;
    double fQ2 = 0;

    std::cout << std::setw(15) << "q1" << std::setw(15) << "q2" << std::setw(15) << "q" << std::setw(15) << "f(q)" << std::endl;
    do
    {
        fQ1 = func(q1);
        fQ2 = func(q2);

        q = avg(q1, q2);
        fQ = func(q);

        std::cout << std::setw(15) << q1 << std::setw(15) << q2 << std::setw(15) << q << std::setw(15) << fQ << std::endl;

        if (fQ * fQ1 < 0)
        {
            q2 = q;
        }
        else
        {
            q1 = q;
        }

    } while (Abs(fQ) > 1e-6);

    std::cout << "computed length is: " << func(q) + L << std::endl;
    std::cout << "progression is: " << std::setprecision(15) << q << std::endl;
    return q;
}

int main()
{
    // std::cout << "insert q1: ";
    // std::cin >> q1;

    // std::cout << "insert q2: ";
    // std::cin >> q2;

    q1 = 1.001;
    // q2 = 0.8;
    q2 = 1.20;

    std::cout << "insert a0: ";
    std::cin >> a0;

    std::cout << "insert L: ";
    std::cin >> L;

    std::cout << "insert n: ";
    std::cin >> n;

    double q = 0;
    try
    {
        q = biSection();
        std::cout << "an = " << (a0 * pow(q, n - 1)) << std::endl;
        std::cout << "delta = " << pow(q, n - 1) << std::endl;
    }
    catch (const char *message)
    {
        return 1;
    }

    return 0;
}