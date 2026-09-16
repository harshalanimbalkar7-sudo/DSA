class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // If there is only one node
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        slow->next = slow->next->next;

        return head;
    }
};