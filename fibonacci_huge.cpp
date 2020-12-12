#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    std::vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(v[0] + v[1]);

    for (int i = 3; (v[i - 1] != 1 || v[i - 2] != 0); i++)
    {
        v.push_back((v[i - 1] + v[i - 2]) % m);
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
        z.push_back((z[i - 1] + z[i - 2]) % m);
    }
    int z_length = z.size() - 1;
    //std::cout << z_length << " zlength\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     std::cout << z[i] << " zelement\n";
    // }

    return z[z_length] % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
