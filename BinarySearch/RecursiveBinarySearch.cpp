#include <iostream>
#include<vector>

using namespace std;

int bsRec(vector<int>& nums, int val, int low, int high) {
    if(low > high) 
        return -1;
    
    int mid = (low + high)/2;
    
    if(nums[mid] == val) 
        return mid;
    else if(nums[mid] > val) 
        return bsRec(nums, val, low, mid - 1);
    else
        return bsRec(nums, val, mid + 1, high);
}


int main(){

}