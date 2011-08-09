#include <iostream>

unsigned
sum_of_multiples(unsigned n, unsigned m)
{
    unsigned n_multiples = (m - 1) / n;
    return (n + n_multiples * n) * n_multiples / 2;
}

int main()
{
    std::cout <<
        sum_of_multiples(3, 1000) +
        sum_of_multiples(5, 1000) -
        sum_of_multiples(15, 1000) << '\n';
}
