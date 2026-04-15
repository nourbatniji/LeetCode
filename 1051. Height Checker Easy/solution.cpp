#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected;

        for (int i = 0; i < heights.size(); i++)
        {
            int key = heights[i];
            expected.push_back(key);

            int j = expected.size() - 2;

            while (j >= 0 && expected[j] > key)
            {
                expected[j + 1] = expected[j];
                j--;
            }
            expected[j + 1] = key;
        }
        int counter = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (expected[i] != heights[i])
            {
                counter++;
            }
        }
        return counter;
    }
};
