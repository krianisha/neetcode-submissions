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
    void reorderList(ListNode* head) {
        vector<int>ans;
        ListNode* temp=head;
        while (temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=ans.size()-1;
        temp=head;
        while(i<=j){
            temp->val=ans[i];
            temp=temp->next;
             if (i == j) {
                break;
            }
            temp->val=ans[j];
            temp=temp->next;
            i++;
            j--;
        }
    }
};
