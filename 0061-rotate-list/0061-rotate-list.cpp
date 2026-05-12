class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         
         if (!head  || !head->next  || k == 0)
              return head;
        
        int L = 1; //for head
        ListNode* tail = head;

        while(tail->next != NULL) {
            tail = tail->next;
            L++;
        }

        k = k%L;
        if (k == 0){
            return head;
        }

        //circular connect(tail will now point to head)
        tail->next = head;

        //k-l
        int remain = L-k;
        ListNode* newTail = head;
        for (int c = 1; c < remain; c++){
            newTail = newTail->next;

        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;

    }
};