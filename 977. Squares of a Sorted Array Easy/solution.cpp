#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //insertion sort
  for (int i = 0; i <nums.size();i++){
            nums[i] = nums[i]*nums[i];
        } 
        for (int i = 1; i <nums.size();i++){
            int j = i - 1;
            int key = nums[i];

            while(j>=0 && nums[j]>key){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }   
        
        return nums;
    }
};

