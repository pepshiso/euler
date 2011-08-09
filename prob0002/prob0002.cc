#include <iostream>

int main()
{
    unsigned sum = 0;
    unsigned fib[] = {1, 2};
    while (fib[1] <= 4000000) {
        if (fib[1]%2 == 0)
            sum += fib[1];
        unsigned tmp = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = tmp;
    }
    std::cout << sum << '\n';
}
