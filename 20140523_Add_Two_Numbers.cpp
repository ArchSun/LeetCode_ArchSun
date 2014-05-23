class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *head, *tail, *tmp;
            head = new ListNode(0);
            tail = head;
            int sum = 0;
            bool carry = false;
            while ( l1&&l2 ) {
                if( carry ) {
                    sum = l1->val + l2->val + 1;
                    carry = false;
                }
                else
                    sum = l1->val + l2->val;

                if ( sum > 9 ){
                    sum = sum - 10;
                    carry = true;
                }

                tmp = new ListNode( sum );
                tail->next = tmp;
                tail = tmp;

                l1 = l1->next;
                l2 = l2->next;
            }
            while ( l1  ) {
                if( carry ) {
                    sum = l1->val + 1;
                    carry = false;
                    if ( sum > 9 ){
                        sum = sum - 10;
                        carry = true;
                    }
                }
                else
                    sum = l1->val;
                tmp = new ListNode( sum );
                tail->next = tmp;
                tail = tmp;

                l1 = l1->next;
            }
            while ( l2  ) {
                if( carry ) {
                    sum = l2->val + 1;
                    carry = false;
                    if ( sum > 9 ){
                        sum = sum - 10;
                        carry = true;
                    }
                }
                else
                    sum = l2->val;

                tmp = new ListNode( sum );
                tail->next = tmp;
                tail = tmp;

                l2 = l2->next;
            }
            if( carry ) {
                carry = false;
                tmp = new ListNode( 1 );
                tail->next = tmp;
                tail = tmp;
            }
        return head->next? head->next : head;
    }
};
