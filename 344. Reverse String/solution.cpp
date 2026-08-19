#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;

    vector<char> a = {'h','e','l','l','o'};   

    sol.reverseString(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
    }            

    return 0;
}