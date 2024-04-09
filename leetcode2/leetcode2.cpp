#include <iostream>
#include <vector>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *current = nullptr;
        ListNode *temp = nullptr;
        int remainder = 0;

        while (l1 != nullptr || l2 != nullptr) {
            current = new ListNode();
            if (temp != nullptr) 
                temp->next = current;
            else 
                head = current;
            temp = current;

            if (l1 != nullptr && l2 != nullptr) {
                current->val = (l1->val + l2->val + remainder)%10;
                remainder = (l1->val + l2->val + remainder)/10;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 == nullptr) {
                current->val = (l2->val + remainder)%10;
                remainder = (l2->val + remainder)/10;
                l2 = l2->next;
            } else {
                current->val = (l1->val + remainder)%10;
                remainder = (l1->val + remainder)/10;
                l1 = l1->next;
            }
        }
        if (remainder != 0) {
            current = new ListNode(remainder);
            temp->next = current;
        }

        return head;        
    }
};

