#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Remember rule of Index conversions
// Brute force solution

void Lrotate(int arry[], int n, int d)
{

  int d = d % n;
  int temp[d];

  for (int i = 0; i < d; i++)
  {

    temp[i] = arry[i];
  }

  for (int i = d; i < n; i++)
  {

    arry[i - d] = arry[i];
  }

  for (int i = n - d; i < n; i++)
  {

    arry[i] = temp[i - (n - d)];
  }
}

int main()
{

  int d;

  cin >> d;

  int arry[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = size 
}