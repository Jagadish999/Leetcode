#include "Solution.h"

#include <iostream>


int main() {
    Solution solu;

    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));

    ListNode* added_list = solu.addTwoNumbers(l1, l2);

    return 0;
}