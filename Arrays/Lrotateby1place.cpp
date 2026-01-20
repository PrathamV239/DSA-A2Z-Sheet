// Redo the main function
// Containers like vector cannot be printed by cout. We need to loop them

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<int> LeftRotate(vector<int> &arr, int n)
{

  int temp = arr[0];

  for (int i = 1; i < n; i++)
  {

    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;

  return arr;
}

int main()
{

  vector<int> arr = {8, 3, 4, 5, 6, 7};
  int n = arr.size();

  vector<int> result = LeftRotate(arr, n);

  cout << "Left rotated Array: ";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
