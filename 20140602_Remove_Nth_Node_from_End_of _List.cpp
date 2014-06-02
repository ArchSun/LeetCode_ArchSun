class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pre = head;
        ListNode *cur = head;
        int i = 0;
        for( i=0; i<n; i++)
            cur = cur->next;
        if(cur==NULL)
            return head->next;
        while(cur->next){
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
