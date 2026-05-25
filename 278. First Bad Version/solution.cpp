// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            for (int i = 0; i < mid + 1; i++) {
                if (isBadVersion(i) == true) {
                    return i;
                }
            }
            for (int i = mid; i < n ; i++) {
                if (isBadVersion(i) == true) {
                    return i;
                }
            }
        }
        return -1;
    }
};