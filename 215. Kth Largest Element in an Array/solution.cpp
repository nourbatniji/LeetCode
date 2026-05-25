#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void maxHeap(vector<int>& nums, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeap(nums, n, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeap(nums, n, i);
        }

        // Heap sort
        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            maxHeap(nums, i, 0);
        }

        return nums[n - k];
    }
};

int main() {
    Solution s;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << s.findKthLargest(nums, k);

    return 0;
}