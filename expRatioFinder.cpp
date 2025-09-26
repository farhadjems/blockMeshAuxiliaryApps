#include <iostream>
#include <cmath>
#include <iomanip>
#include <memory>

double q1, q2, a0, L;
int n = 0;

int wt = 20;

double func(double q)
{
    double result = 0;
    
    if (q == 1)
    {
        result = a0;
        for (int i = 1; i < n+1; i++)
        {
            result += a0*pow(q, n);
        }
        result -= L;
    }
    else
    {
        result = a0 * (1 - pow(q, n)) / (1 - q) - L;
    }
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
    std::cout << "\n----------BI SECTION METHOD----------\n";
    if (func(q1) * func(q2) > 0)
    {
        std::cerr << "inserted initial guess for q1 and q2 are not suitable!\n";
        std::cout << func(q1) << '\t' << func(q2) << std::endl
                  << "quitting...\n";
        throw "error in initialization";
    }

    double q = 0;
    double fQ = 0;
    double fQ1 = 0;
    double fQ2 = 0;

    std::cout << std::setw(wt) << "q1" << std::setw(wt) << "q2" << std::setw(wt) << "q" << std::setw(wt) << "f(q)" << std::endl;
    
    int iter = 0;
    do
    {
        fQ1 = func(q1);
        fQ2 = func(q2);

        q = avg(q1, q2);
        fQ = func(q);

        std::cout << std::setw(wt) << q1 << std::setw(wt) << q2 << std::setw(wt) << q << std::setw(wt) << fQ << std::endl;

        if (fQ * fQ1 < 0)
        {
            q2 = q;
        }
        else
        {
            q1 = q;
        }
        iter++;
        if (iter > 50)
        {
            throw "could not solve the equation by biSection method, throwing exception...\n";
        }
        
    } while (Abs(fQ) > 1e-6);

    std::cout << "computed length is: " << func(q) + L << std::endl;
    std::cout << "progression is: " << std::setprecision(10) << q << std::endl;
    std::cout << "n = " << n << "\n";
    return q;
}

int main()
{
    

    std::cout << "insert a0: ";
    std::cin >> a0;

    std::cout << "insert L: ";
    std::cin >> L;

    double qMax;
    std::cout << "insert maximum of progression: ";
    std::cin >> qMax;
    std::cin.ignore();
    
    double q = 0;
    double an = 0;

    n = 1;

    do
    {
        q1 = 1.0;
        q2 = qMax;
        try
        {
            q = biSection();
        }
        catch (const char *message)
        {
            std::cout << "n = " << n << " was not enough, increasing n for next try...\n";
            n++;
            continue;
        }

        an = a0 * pow(q, n - 1);
        std::cout << "last cell size: " << an << std::endl;
        std::cin.get();
        n++;

    } while (true);
    std::cout << "number of elements: " << n << std::endl;
    std::cout << "progression is: " << q << std::endl;

    return 0;
}