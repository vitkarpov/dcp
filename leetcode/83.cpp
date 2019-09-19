/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;

    while (curr && curr->next) {
      if (curr->next->val == curr->val) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};
