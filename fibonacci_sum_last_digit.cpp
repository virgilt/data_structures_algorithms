#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n)
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
        sum += current;
    }

    return sum % 10;
}
// const long long max = 1000;
// long long f[max];

// std::vector<long long> f;
// std::vector<long long>::iterator it = f.begin();

long long fib_num(long long n)
{
    // it += 0;

    // if (n == 0)
    // {
    //     return 0;
    // }
    // if (n == 1 || n == 2)
    // {
    //     f.push_back(1);
    //     it -= n;
    // }

    // long long k = (n & 1) ? (n + 1) / 2 : (n / 2);
    // long long y = (n & 1) ? (2 * fib_num(k - 1) + fib_num(k)) * fib_num(k) : fib_num(k) * fib_num(k) + fib_num(k - 1) * fib_num(k - 1);

    // f.push_back(y);

    // return f[f.size() - 1] % 10;

    std::vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(v[0] + v[1]);

    for (int i = 3; (v[i - 1] != 1 || v[i - 2] != 0); i++)
    {
        v.push_back((v[i - 1] + v[i - 2]) % 100);
        //std::cout << v[i] << "\n";
    }

    int v_length = v.size() - 2;
    //std::cout << v_length << " vlength\n";
    int remainder = n % v_length;
    //std::cout << remainder << " remainder\n";

    if (remainder <= 1)
    {
        return remainder;
    }

    std::vector<int> z;
    z.push_back(0);
    z.push_back(1);

    for (int i = 2; i <= remainder; ++i)
    {
        z.push_back((z[i - 1] + z[i - 2]) % 100);
        //std::cout << i << " i\n";
    }
    int z_length = z.size() - 1;
    //std::cout << z_length << " zlength\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     std::cout << z[i] << " zelement\n";
    // }
    //std::cout << remainder << " remainder\n";
    return z[z_length] % 100;
}

long long fibonacci_sum_fast(long long n)
{
    return ((long long)fib_num(n + 2) - 1) % 10;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << "\n";
    std::cout << fibonacci_sum_fast(n);
}
