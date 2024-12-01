#include "Solution.h"


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    return _add_two_numbers(l1, l2);
}


ListNode* Solution::_add_two_numbers(ListNode* p_l1, ListNode* p_l2, int p_carry_num) {
    if(p_l1 == nullptr && p_l2 == nullptr) {
        if (p_carry_num != 0) {
            ListNode* temp_list = new ListNode(p_carry_num);
            return temp_list;
        }

        return nullptr;
    }
    else if(p_l1 == nullptr) {
        p_l1 = new ListNode(0, nullptr);
    }
    else if(p_l2 == nullptr) {
        p_l2 = new ListNode(0, nullptr);
    }

    int m_sum = p_l1->val + p_l2->val + p_carry_num;
    int m_carry_num = 0;

    if (m_sum > 9) {
        m_carry_num = 1;
        m_sum %= 10;
    }

    ListNode* m_added_list = new ListNode(
        m_sum, 
        _add_two_numbers(p_l1->next, p_l2->next, m_carry_num)
    );

    return m_added_list;
}