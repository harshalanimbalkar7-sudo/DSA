class Solution {
public:

    // Merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach remaining nodes
        if (list1 != NULL)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }


    // Find middle and split the list
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }


    ListNode* sortList(ListNode* head) {

        // Empty list or single node is already sorted
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* middle = getMiddle(head);

        // Split into two halves
        ListNode* right = middle->next;
        middle->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        right = sortList(right);

        // Merge sorted halves
        return merge(left, right);
    }
};