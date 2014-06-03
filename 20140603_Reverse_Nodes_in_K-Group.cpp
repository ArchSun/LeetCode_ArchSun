/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool revK( ListNode* head, ListNode** &pCur, ListNode * &nxt, int i, int k) {
        if( i==k) {
            nxt = head->next;
            *pCur = head;
            pCur = &((*pCur)->next);
            return true;
        }
        if( head->next && revK( head->next, pCur, nxt, i+1, k)) {
            *pCur = head;
            pCur = &((*pCur)->next);
            return true;
        }
        else
            return false;
    } 
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        ListNode *nxt = NULL;
        while( head && revK( head, pCur, nxt, 1, k)) {
            head = nxt;
        }
        *pCur = head;
        return ret;
    }
};
