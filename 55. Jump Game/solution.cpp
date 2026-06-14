#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = nums[0];

    for (int i = 0; i < nums.size(); i++) {
        if (i > farthest)
            return false;

        farthest = max(farthest, i + nums[i]);
    }

    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    if (canJump(nums))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}