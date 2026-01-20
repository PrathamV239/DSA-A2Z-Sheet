#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &arry, int target)
{

  int n = arry.size();
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {

    int mid = low + (high - low) / 2;
    if (arry[mid] == target)
    {
      return mid;
    }
    else if (arry[mid] > target)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return -1;
}

int main()
{

  vector<int> arry = {1, 3, 5, 6, 7, 10, 11, 13};
  int target = 7;
  int index = BinarySearch(arry, target);

  if (index != -1)
  {
    cout << "Target found at: " << index << endl;
  }
  else
    cout << "Target was not found in the array.";
  return 0;
}