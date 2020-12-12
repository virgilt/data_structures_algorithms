#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long remove_i(vector<int> c)
{
  long long n = c.size();
  long long x = 0;
  long long c_i = 0;

  for (int i = 0; i < n; i++)
  {
    if (c[i] > x)
    {
      x = c[i];
      c_i = i;
    }
  }
  return c_i;
}

long long max_dot_product(vector<int> a, vector<int> b)
{
  // write your code here
  long long n = a.size();
  long long result = 0;

  for (long long i = 0; i < n; i++)
  {
    long long a_i = remove_i(a);

    long long b_i = remove_i(b);

    result += ((long long)a[a_i] * (long long)b[b_i]);

    a.erase(a.begin() + a_i);
    b.erase(b.begin() + b_i);
  }

  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
