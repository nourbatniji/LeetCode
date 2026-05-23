#include <iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) {

    int five = 0;
    int ten = 0;

    for (int bill : bills) {

        // customer gives 5
        if (bill == 5) {
            five++;
        }

        // customer gives 10
        else if (bill == 10) {

            if (five == 0) {
                return false;
            }

            five--;
            ten++;
        }

        // customer gives 20
        else {

            // use 10 + 5
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            }

            // use three 5s
            else if (five >= 3) {
                five -= 3;
            }

            else {
                return false;
            }
        }
    }

    return true;
}

int main() {

    vector<int> bills = {5, 5, 10, 20};

    if (lemonadeChange(bills)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}