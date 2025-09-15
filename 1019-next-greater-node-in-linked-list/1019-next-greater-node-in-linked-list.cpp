 class Solution {
public:
    ListNode *reverseLL(ListNode * head){
        if(!head) return head;
        ListNode *temp,*prev=NULL;
        while(head){                                            // reversing the linked list
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<int> st;
        head=reverseLL(head);
        while(head){                                            // traversing the LL from backwards(as we reversed the LL)
            if(st.empty()){                                     
                result.push_back(0);
                st.push(head->val);
                head=head->next;
            }
            else if(st.top()>head->val){
                result.push_back(st.top());
                st.push(head->val);
                head=head->next;    
            }
            else     st.pop();
        }
     // reversing the result vector for getting the resultant output (as we had reversed the LL then found out the greater node to it)
        reverse(result.begin(),result.end());                  
        return result;
    }
};