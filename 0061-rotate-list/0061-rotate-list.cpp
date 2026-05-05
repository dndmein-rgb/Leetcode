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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        int n=1;
        ListNode* curr=head;
        while(curr->next){
            curr=curr->next;
            n++;
        }
        k=k%n;
        curr->next=head;
        int steps=n-k-1;
        curr=head;
        while(steps){
            curr=curr->next;
            steps--;
        }
        ListNode* newHead=curr->next;
        curr->next=NULL;
        return newHead;

    }
};