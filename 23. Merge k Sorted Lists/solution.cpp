#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 != nullptr && l2 != nullptr) {

            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if (l1 != nullptr)
            tail->next = l1;
        else
            tail->next = l2;

        return dummy.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {

        if (left > right)
            return nullptr;

        if (left == right)
            return lists[left];

        int mid = left + (right - left) / 2;

        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty())
            return nullptr;

        return merge(lists, 0, lists.size() - 1);
    }
};

void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // List 1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // List 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // List 3: 2 -> 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution s;

    ListNode* result = s.mergeKLists(lists);

    printList(result);

    return 0;
}