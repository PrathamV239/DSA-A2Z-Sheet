#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int SecondLargestElement(vector<int> &arry, int n)
{

  /*Better


  int largest = arry[0];
  for (int i = 0; i < n; i++)
  {
    if (arry[i] > largest)
    {
      largest = arry[i];
    }
  }


  int Seclargest = -1;
  for (int j = 0; j < n; j++)
  {
    if (arry[j] > Seclargest && arry[j] < largest)
    {
      Seclargest = arry[j];
    }
  }
  return Seclargest;

*/

int largest = arry[0], slargest = INT_MIN;

for (int i = 0 ; i < n; i++){

  if (arry[i]> largest){
    slargest = largest;
    largest = arry[i];
  }
  else if(arry[i] < largest && arry[i]> slargest){

    slargest = arry[i];
  }


}
return slargest; 
}

int main()
{

  vector<int> arry = {4, 5, 7, 8, 4, 2, 6, 9,100,120};

  int n = arry.size();

  cout << "Second Largest Element: " << SecondLargestElement(arry, n) << endl;
  return 0;

}