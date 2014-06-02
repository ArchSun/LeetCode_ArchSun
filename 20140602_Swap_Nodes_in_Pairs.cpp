class Solution {
public:
    ListNode *swapPairs( ListNode *head) {
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        ListNode *nextNd = NULL;
        while( head && head->next){
            nextNd = head->next->next;
            *pCur = head->next;
            pCur = &((*pCur)->next);
            *pCur = head;
            pCur = &((*pCur)->next);
            head = nextNd;
        }
        *pCur = head;
        return ret;
    }
};
