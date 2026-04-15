#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> arr(nums.size());
        int left = 0;
        int right = arr.size() - 1;

        for (int i = 0; i<nums.size();i++){
            if(nums[i] %2 ==0){
                arr[left] = nums[i];
                left++;
            }else{
                arr[right] = nums[i];
                right--;
            }
        }
    return arr;
    }
};