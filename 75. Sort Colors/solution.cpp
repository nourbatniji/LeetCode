#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int pivot = partition(nums, low, high);

        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution s;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    s.sortColors(nums);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}