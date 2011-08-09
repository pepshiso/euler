#include <cmath>
#include <iostream>
#include <vector>

class primes {
    typedef std::vector<unsigned> container;

public:
    typedef container::const_iterator iterator;

    explicit primes(unsigned long long n) {
        unsigned long long const upper_bound = std::sqrt(n);
        primes_.push_back(2);
        primes_.push_back(3);
        for (unsigned i = 5; i <= upper_bound; i += 2) {
            unsigned const ub = std::sqrt(i);
            bool is_prime = true;
            for (unsigned j = 0, size = primes_.size(); j < size && primes_[j] < ub; ++j)
                if (i%primes_[j] == 0) {
                    is_prime = false;
                    break;
                }
            if (is_prime)
                primes_.push_back(i);
        }
    }

    iterator cbegin() const {
        return primes_.begin();
    }
    iterator cend() const {
        return primes_.end();
    }

private:
    container primes_;
};

int main()
{
    unsigned long long n = 600851475143ULL;
    primes p(n);
    for (primes::iterator it = p.cbegin(), end = p.cend(); it != end; ++it) {
        if (n % *it == 0) {
            n /= *it;
            if (n == 1) {
                std::cout << *it << '\n';
                break;
            }
        }
    }
}
