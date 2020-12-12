#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long fib_fast(long long m)
{
    std::vector<int> z;
    z.push_back(0);
    z.push_back(1);
    long long total = 0;

    if (m == 0)
    {
        return 0;
    }
    if (m == 1)
    {
        return 1;
    }

    for (int i = 2; i <= m; ++i)
    {
        long long z_value = (z[i - 1] + z[i - 2]) % 10;
        z.push_back(z_value);
        total += ((z[i] % 10) * z[i] % 10);
        total %= 10;
        // std::cout << z[i] << "zvalue\n";
        // std::cout << total + 1 << "total\n";
        //std::cout << i << " i\n";
    }

    int z_length = z.size() - 1;
    //std::cout << total << "zsize\n";

    return (long long)total + 1;
}

long long get_fibonacci_sum_squares_fast(long long n)
{
    //n = n % 60;

    long long n_remainder = n;
    //= (n) % 60;

    while (n_remainder >= 60)
    {
        n_remainder %= 60;
    }

    //std::cout << n_remainder << "nremainder\n";

    long long to_last;

    to_last = fib_fast(n_remainder);

    long long result = to_last % 10;
    //std::cout << result << "result\n";

    return result;
}

long long fibonacci_sum_squares_fast(long long n)
{
    int mod = (((long long)get_fibonacci_sum_squares_fast(n)) % 10);

    return mod;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n);
    std::cout << fibonacci_sum_squares_fast(n);
}
