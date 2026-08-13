class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* newhead = NULL;
        ListNode* newtail = NULL;

        if(list1->val < list2->val) {
            newhead = list1;
            newtail = list1;
            list1 = list1->next;
        }
        else {
            newhead = list2;
            newtail = list2;
            list2 = list2->next;
        }

        while(list1 != nullptr && list2 != nullptr) {

            if(list1->val < list2->val) {

                newtail->next = list1;
                newtail = list1;
                list1 = list1->next;
            }
            else {

                newtail->next = list2;
                newtail = list2;
                list2 = list2->next;
            }
        }

        while(list1 != nullptr) {
            newtail->next = list1;
            newtail = list1;
            list1 = list1->next;
        }

        while(list2 != nullptr) {
            newtail->next = list2;
            newtail = list2;
            list2 = list2->next;
        }

        return newhead;
    }
};