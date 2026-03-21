#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& arr, int lb, int mid, int ub) {
        int i = lb;
        int j = mid + 1;

        vector<int> temp;

        // check who is smaller and append
        while (i <= mid && j <= ub) {
            if (arr[i] < arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        // check if limit is exceeded
        if (i > mid) {
            while (j <= ub) {
                temp.push_back(arr[j]);
                j++;
            }
        } else {
            while (i <= mid) {
                temp.push_back(arr[i]);
                i++;
            }
        }
        // copy sorted temp into arr
        for (int k = 0; k < temp.size(); k++) {
            arr[lb + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& arr, int lb, int ub) {
        if (lb < ub) {
            int mid = (lb + ub) / 2;
            mergeSort(arr, lb, mid);
            mergeSort(arr, mid + 1, ub);
            merge(arr, lb, mid, ub);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};


int main(){
    Solution sol;

    vector<int> arr = {5, 2, 8, 1, 3};

    vector<int> result = sol.sortArray(arr);

    for(int x : result)
        cout << x << " ";
}