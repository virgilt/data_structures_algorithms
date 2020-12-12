#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long fib_fast(long long m)
{
    std::vector<int> z;
    z.push_back(0);
    z.push_back(1);

    for (int i = 2; i <= m; ++i)
    {
        z.push_back((z[i - 1] + z[i - 2]));
        //std::cout << i << " i\n";
    }

    int z_length = z.size() - 1;

    return (long long)(z[z_length]);
}

long long get_fibonacci_partial_sum_fast(long long m, long long n)
{
    m = m % 60;
    n = n % 60;

    long long m_remainder = (m + 1) % 60;
    long long n_remainder = (n + 2) % 60;

    long long from_last, to_last;

    from_last = fib_fast(m_remainder) - 1;
    to_last = fib_fast(n_remainder) - 1;

    if (from_last > to_last)
    {
        from_last = from_last % 60;
    }

    long long result = (to_last - from_last) % 10;

    if (result < 0)
    {
        return result * -1;
    }
    return result;

    // std::vector<int> v;

    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(v[0] + v[1]);

    // for (int i = 3; (v[i - 1] != 1 || v[i - 2] != 0); i++)
    // {
    //     v.push_back((v[i - 1] + v[i - 2]) % 10000);
    //     //std::cout << v[i] << "\n";
    // }

    // int v_length = v.size() - 2;
    // //std::cout << v_length << " vlength\n";
    // int remainder = n % v_length;
    // //std::cout << remainder << " remainder\n";

    // if (remainder <= 1)
    // {
    //     return remainder;
    // }

    //std::cout << z_length << " zlength\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     std::cout << z[i] << " zelement\n";
    // }
    //std::cout << remainder << " remainder\n";
    // std::cout << z[m] << " M\n";
    // std::cout << z[z_length] << " N\n";
}

long long fibonacci_partial_sum_fast(long long m, long long n)
{
    int mod = ((long long)get_fibonacci_partial_sum_fast((m), (n)) % 10);

    return mod;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << fibonacci_partial_sum_fast(from, to) << '\n';
}
