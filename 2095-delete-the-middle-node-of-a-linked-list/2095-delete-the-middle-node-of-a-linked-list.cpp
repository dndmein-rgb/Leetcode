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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* start=head;
        int n=0;
        while(start){
            start=start->next;
            n++;
        }
        if(n==1)return NULL;
        int mid=n/2;

        ListNode*prev=NULL;
        start=head;
        while(mid){
            prev=start;
            start=start->next;
            mid--;
        }
        ListNode* temp=start->next;
        start->next=NULL;
        prev->next=temp;

        return head;

    }
};