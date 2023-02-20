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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        unordered_map<int,ListNode*> mp;
        int sum=0;
        for(ListNode* curr=prehead;curr!=NULL;curr=curr->next){
            sum+=curr->val;
            mp[sum]=curr->next;
        }
        sum=0;
        ListNode* curr=prehead;
        while(curr!=NULL){
            sum+=curr->val;
            curr->next=mp[sum];
            curr=mp[sum];
        }
        return prehead->next;
    }
};
