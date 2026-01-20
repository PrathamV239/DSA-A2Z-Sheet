#include <bits/stdc++.h>
using namespace std;

pair<int,int> FloorAndCeil(vector<int>& nums, int target) {
    int n = nums.size();

    // -------- FLOOR --------
    int low = 0, high = n - 1;
    int floorIdx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target) {
            floorIdx = mid;      
            low = mid + 1;       // go right
        } else {
            high = mid - 1;
        }
    }

    // -------- CEIL --------
    low = 0; 
    high = n - 1;
    int ceilIdx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ceilIdx = mid;     
            high = mid - 1;      // go left
        } else {
            low = mid + 1;
        }
    }

    return {floorIdx, ceilIdx};
}



  int main() {
    vector<int> nums = {1,2,3,4,5,5,5,5,7,8};
    int target = 6;

    auto result = FloorAndCeil(nums, target);

    cout << "Floor index: " << result.first << endl;
    cout << "Ceil index: " << result.second << endl;

    if (result.first != -1)
        cout << "Floor value: " << nums[result.first] << endl;

    if (result.second != -1)
        cout << "Ceil value: " << nums[result.second] << endl;

    return 0;
}


