#include <iostream>
#include <vector>

using std::vector;

int select_i(vector<int> weights, vector<int> values)
{
  int max_i = 0;
  double max = 0;

  for (int i = 0; i < weights.size(); i++)
  {
    if (weights[i] > 0 && (double)values[i] / weights[i] > max)
    {
      max = (double)values[i] / weights[i];
      max_i = i;
    }
  }
  return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double V = 0.0;

  for (int i = 0; i < weights.size(); i++)
  {
    if (capacity == 0)
    {
      return V;
    }
    int j = select_i(weights, values);
    int a = std::min(weights[j], capacity);
    V += a * (double)values[j] / weights[j];
    weights[j] -= a;
    capacity -= a;
  }
  // write your code here

  return V;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}