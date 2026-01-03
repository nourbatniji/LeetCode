#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int number) {
        if (number < 0) return false;

        int original = number;
        int rev = 0;

        while (number > 0) {
            rev = rev * 10 + number % 10;
            number /= 10;
        }

        return rev == original;
    }
};

int main() {
    Solution s;
    int x;

    cout << "Enter a number: ";
    cin >> x;

    if (s.isPalindrome(x))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
