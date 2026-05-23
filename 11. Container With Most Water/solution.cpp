#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxarea = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int width = right - left;
        int area = width * h;

        maxarea = max(maxarea, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxarea;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum Area = " << maxArea(height);

    return 0;
}