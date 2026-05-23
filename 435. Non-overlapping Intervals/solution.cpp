#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compare(Interval firstInterval,
             Interval secondInterval) {

    return firstInterval.end <
           secondInterval.end;
}

int eraseOverlapIntervals(vector<Interval>& intervals) {

    sort(intervals.begin(),
         intervals.end(),
         compare);

    int removed = 0;

    int lastEnd =
        intervals[0].end;

    for (int i = 1;
         i < intervals.size();
         i++) {

        // overlap exists
        if (intervals[i].start < lastEnd) {

            removed++;
        }

        // no overlap
        else {

            lastEnd =
                intervals[i].end;
        }
    }

    return removed;
}

int main() {

    vector<Interval> intervals = {

        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}

    };

    cout << "Removed intervals = "
         << eraseOverlapIntervals(intervals);

    return 0;
}