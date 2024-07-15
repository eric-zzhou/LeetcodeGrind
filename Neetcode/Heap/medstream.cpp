#include <queue>
using namespace std;

class MedianFinder
{
public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    if (!large.empty() && num > large.top())
    {
      large.push(num);
    }
    else
    {
      small.push(num);
    }

    if (large.size() > small.size() + 1)
    {
      small.push(large.top());
      large.pop();
    }
    else if (large.size() < small.size() - 1)
    {
      small.push(large.top());
      large.pop();
    }
  }

  double findMedian()
  {
    if (large.size() > small.size())
    {
      return large.top();
    }
    else if (large.size() < small.size())
    {
      return small.top();
    }
    else
    {
      return (large.top() - small.top()) / 2.0;
    }
  }

private:
  priority_queue<double, vector<double>> small;
  priority_queue<double, vector<double>, greater<double>> large;
};
