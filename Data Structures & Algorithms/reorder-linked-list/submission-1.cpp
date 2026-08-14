class Solution {
public:
    void reorderList(ListNode* head) {

        // 1. Find length
        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        // 2. Find middle
        temp = head;
        int mid = n / 2;

        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        // 3. Separate second half
        ListNode* second = temp->next;
        temp->next = NULL;

        // 4. Reverse second half
        ListNode* prev = NULL;

        while (second != NULL) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // 5. Merge - easy way
        second = prev;
        temp = head;

        while (second != NULL) {
            ListNode* save = temp->next;

            temp->next = second;
            second = second->next;

            temp->next->next = save;

            temp = save;
        }
    }
};