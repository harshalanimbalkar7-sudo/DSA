class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (head == NULL || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            
            // Find the kth node of the current group
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == NULL)
                    return dummy.next;
            }

            // Save the node after the current group
            ListNode* groupNext = kth->next;

            // Reverse the current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* nextNode = curr->next;

                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect previous group to reversed group
            ListNode* oldGroupStart = groupPrev->next;
            groupPrev->next = kth;

            // Move groupPrev to the end of reversed group
            groupPrev = oldGroupStart;
        }

        return dummy.next;
    }
};