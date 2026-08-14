/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
           temp=temp->next;

        }
        if(n == len){
        ListNode* del = head;
        head = head->next;
        delete del;
        return head;
         }
         
        int index=len-n-1;
        int x=0;
        temp=head;
        while(temp!=NULL && x!=index){
            temp=temp->next;
            x++;
        }
        
        ListNode* del=temp->next;
        temp->next=temp->next->next;
        delete(del);
        return head;

    }
};
