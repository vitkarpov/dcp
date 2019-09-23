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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode fakeHead(0);
    fakeHead.next = head;

    ListNode* prev = &fakeHead;
    ListNode* curr = head;

    while (curr) {
      if (curr->val == val) {
        prev->next = curr->next;
      } else {
        prev = curr;
      }
      curr = curr->next;
    }
    return fakeHead.next;
  }
};
